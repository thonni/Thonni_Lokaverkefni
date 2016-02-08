#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "stdio.h"
#include "string"
#include "EventHandler.h"
#include "Objects.h"
#include "GameTime.h"
#include "windows.h"

//Create window width and height
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

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
		Sleep(1000);
		return -1;
	}
	
	bool run = true;
	
	EventHandler e;
	GameTime t;

	std::vector<Obj_MainParent*> objects;
	objects.push_back(new Obj_Player(renderer, 50, 50));
	objects.push_back(new Obj_Wall(renderer, 200, 200));

	//Main game loop
	while (run)
	{
		//EVENTS
		e.update();
		t.update();

		//Exit event or escape key
		if (e.getKeyHeld(SDLK_ESCAPE) || e.getEvent(SDL_QUIT))
			run = false;
			
		
		//UPDATES
		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->update(e, t);
		}

		//RENDERING
		//Clear the renderer (Screen)
		SDL_RenderClear(renderer);

		for (int i = 0; i < objects.size(); i++)
		{
			objects[i]->render();
		}

		//Update the renderer (Screen)
		SDL_RenderPresent(renderer);
	}

	return 0;
}

//A function that runs when the game starts
bool Initialize()
{
	//Initiate SDL Video and checks if there is an error
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
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