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

	int width;                      //Width of object

	int height;                     //Height of object

	Sprite* sprite;                 //Holds the sprite

	bool solid;                     //If the object is solid

	bool visible;                   //If the object is visible

	bool active;                    //If the object is active (if not it is not updateted or rendered)


public:

	Obj_MainParent(SDL_Renderer*, int, int);            //Constructor

	void mainUpdate(EventHandler, GameTime);            //The main update, does important things

	virtual void update(EventHandler, GameTime);        //The update that children of the class can change

	void render(int, int);                              //Renders the object sprite

	void setSprite(std::string, int, int, int, float);  //Change the sprite

	//Getters and Setters

	void setActive(bool);

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