#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "stdio.h"
#include "string"
#include "EventHandler.h"
#include "Objects.h"
#include "GameTime.h"
#include "windows.h"
#include "Rooms.h"
#include "SDL_mixer.h"

//Create window width and height
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

//Create functions
bool Initialize();
void Close();

//Create the window and the renderer
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main(int argc, char* args[])
{
	//Run and check if the initialize function returns false
	//and if so, it prints an error and ends the program
	if (!Initialize())
	{
		printf("Could not initialize!\n");
		return -1;
	}
	
	bool run = true;
	
	EventHandler e;
	GameTime t;

	//Create a Vector (List) of all Rooms (Levels)
	std::vector<Room_MainParent*> rooms
	{
		new Room_TestRoom(renderer, 2000, 2000, 0, 0)
	};

	//Main game loop
	while (run)
	{
		//EVENTS
		e.update();
		t.update();

		//Exit event or escape key
		if (e.getEvent(SDL_QUIT))
			run = false;

		//Update the current room
		rooms[0]->mainUpdate(e, t);
		//rooms[0]->update(e, t);

		//RENDERING
		//Clear the Window
		SDL_RenderClear(renderer);

		//Render all items in the current room
		rooms[0]->mainRender();

		//Update the renderer (Screen)
		SDL_RenderPresent(renderer);
	}

	return 0;
}



//A function that runs when the game starts to initialize things
bool Initialize()
{
	//Initiate SDL Video and checks if there is an error
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
		Sleep(1000);
		return false;
	}

	//Create the window
	window = SDL_CreateWindow("Leikurinn Minn",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//Checks if there is an error when creating the window
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		Sleep(1000);
		return false;
	}

	//Create the renderer and if there is an error it will display
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("We were not able to create the renderer! SDL Error %s\n", SDL_GetError());
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "SDL Mixer Error!" << endl;
	}

	SDL_SetRenderDrawColor(renderer, 144, 195, 212, 255);
	
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		return false;
	}

	return true;
}



//A function that handles closing the program
void Close()
{
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}