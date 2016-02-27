#include "Rooms.h"



Room_MainParent::Room_MainParent(SDL_Renderer* rendererIn, int width, int height, int camXIn, int camYIn)
{
	//Set variables
	room_width = width;
	room_height = height;
	camX = camXIn;
	camY = camYIn;
	renderer = rendererIn;
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