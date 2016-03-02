#include "Rooms.h"



Room_MainParent::Room_MainParent(SDL_Renderer* rendererIn, int width, int height, int camXIn, int camYIn)
{
	//Set variables
	room_width = width;
	room_height = height;
	camX = camXIn;
	camY = camYIn;
	renderer = rendererIn;
	music = NULL;
}

void Room_MainParent::mainUpdate(EventHandler e, GameTime t)
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->mainUpdate(e, t, objects);
	}
	update(e, t);
}

void Room_MainParent::update(EventHandler e, GameTime t){}

void Room_MainParent::mainRender()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->render(camX, camY);
	}
	render();
}

void Room_MainParent::render()
{
	false;
}

void Room_MainParent::setMusic(const char *path, bool play)
{
	music = Mix_LoadMUS(path);
	if (music == NULL)
	{
		std::cout << "Could not play music with path '" << path << "'!" << endl;
	}
	else 
	{
		Mix_PlayMusic(music, -1);
		if (!play)
			Mix_PauseMusic();
	}
}

void Room_MainParent::musicPause()
{
	if (Mix_PausedMusic() == false)
		Mix_PauseMusic();
}

void Room_MainParent::musicPlay()
{
	if (Mix_PausedMusic() == true)
		Mix_ResumeMusic();
}