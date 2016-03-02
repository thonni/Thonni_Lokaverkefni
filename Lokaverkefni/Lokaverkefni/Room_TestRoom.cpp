#include "Rooms.h"



Room_TestRoom::Room_TestRoom(SDL_Renderer* rendererIn, int width, int height, int camXIn, int camYIn)
	:Room_MainParent(rendererIn, width, height, camXIn, camYIn)
{
	objects.push_back(new Obj_Player(idHandler.getId(), renderer, 50, 50));
	objects.push_back(new Obj_Wall(idHandler.getId(), renderer, 200, 200));
	objects.push_back(new Obj_Wall(idHandler.getId(), renderer, 600, 300));

	setMusic("resources/audio/DragonRoostIsland.wav", false);
}

void Room_TestRoom::update(EventHandler e, GameTime t)
{
	if (e.getKeyPressed(SDLK_r))
		musicPause();
	if (e.getKeyPressed(SDLK_t))
		musicPlay();
}