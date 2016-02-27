#include "Rooms.h"



Room_TestRoom::Room_TestRoom(SDL_Renderer* rendererIn, int width, int height, int camXIn, int camYIn)
	:Room_MainParent(rendererIn, width, height, camXIn, camYIn)
{
	objects.push_back(new Obj_Player(idHandler.getId(), renderer, 50, 50));
	objects.push_back(new Obj_Wall(idHandler.getId(), renderer, 200, 200));
	objects.push_back(new Obj_Wall(idHandler.getId(), renderer, 600, 300));
}

void Room_TestRoom::update(EventHandler e, GameTime t)
{
	if (e.getKeyHeld(SDLK_RIGHT))
		camX += t.getDeltaTime() * 10;

	cout << camX << endl;
}