#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Objects.h"

class Room_MainParent
{
protected:
	int room_width;

	int room_height;

	int camX;

	int camY;

	SDL_Renderer* renderer;

	std::vector<Obj_MainParent*> objects;  //Vector (array) of all objects in this room

public:
	Room_MainParent(SDL_Renderer*, int, int, int, int);

	void mainUpdate(EventHandler e, GameTime t);

	void update(EventHandler e, GameTime t);

	void mainRender();

	void render();
};


//A room for testing
class Room_TestRoom: public Room_MainParent
{
private:


public:
	Room_TestRoom(SDL_Renderer*, int, int, int, int);
	void update(EventHandler, GameTime);
};