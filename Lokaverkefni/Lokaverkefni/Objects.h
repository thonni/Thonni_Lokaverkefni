#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "string"
#include "EventHandler.h"
#include "Sprite.h"
#include "GameTime.h"


/*------------------------------------
//This class is the main parent for other objects to use
*/
class Obj_MainParent
{
protected:

	SDL_Renderer* renderer;         //Holds the renderer pointer

	float x;                        //X Position

	float y;                        //Y Position

	Sprite* sprite;                 //Holds the sprite


public:

	Obj_MainParent(SDL_Renderer*, int, int);       //Constructor

	void mainUpdate(EventHandler, GameTime);       //The main update, does important things

	virtual void update(EventHandler, GameTime);   //The update that children of the class can change

	void render(int, int);                         //Renders the object sprite

};

/*------------------------------------
//The player object
*/
class Obj_Player: public Obj_MainParent
{
public:
	Obj_Player(SDL_Renderer*, int, int);           //Constructor

	void update(EventHandler, GameTime);           //The update function, runs each frame

};

/*------------------------------------
//A wall
*/
class Obj_Wall : public Obj_MainParent
{
public:
	Obj_Wall(SDL_Renderer*, int, int);             //Constructor

	void update(EventHandler, GameTime);           //The update function, runs each frame

};