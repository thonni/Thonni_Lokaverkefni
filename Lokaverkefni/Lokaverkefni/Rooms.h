#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Objects.h"

/*
//The main room parent that all other rooms inherit
*/
class Room_MainParent
{
protected:
	int room_width;                        //The room width

	int room_height;                       //The room height

	int camX;                              //X position of the camera

	int camY;                              //Y position of the camera

	SDL_Renderer* renderer;                //Holds the pointer to the renderer

	std::vector<Obj_MainParent*> objects;  //Vector (array) of all objects in this room

public:
	Room_MainParent(SDL_Renderer*, int, int, int, int);   //Constructor
	
	void mainUpdate(EventHandler e, GameTime t);          //An update that does important things

	void update(EventHandler e, GameTime t);              //The update that children of the class can change

	void mainRender();                                    //Renders all objects in the room

	void render();                                        //Optional render if needed (Can be change by children of this class)
};


/*
//A test room
*/
class Room_TestRoom: public Room_MainParent
{
private:


public:
	Room_TestRoom(SDL_Renderer*, int, int, int, int);

	void update(EventHandler, GameTime);
};