#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "string"
#include "EventHandler.h"
#include "Sprite.h"
#include "GameTime.h"
#include "Collider.h"


/*------------------------------------
//This class is the main parent for other objects to use
*/
class Obj_MainParent
{
protected:

	int id;                         //The object's id
	
	SDL_Renderer* renderer;         //Holds the renderer pointer

	Collider* collider;             //Holds the collider object

	float x;                        //X Position

	float y;                        //Y Position

	int width;                      //Width of object

	int height;                     //Height of object

	Sprite* sprite;                 //Holds the sprite

	bool solid;                     //If the object is solid

	bool visible;                   //If the object is visible

	bool active;                    //If the object is active (if not it is not updateted or rendered)


public:

	Obj_MainParent(int, SDL_Renderer*, int, int);       //Constructor

	void mainUpdate(EventHandler, GameTime, std::vector<Obj_MainParent*>);            //The main update, does important things

	virtual void update(EventHandler, GameTime, std::vector<Obj_MainParent*>);        //The update that children of the class can change

	void render(int, int);                              //Renders the object sprite

	void setSprite(std::string, int, int, int, float);  //Change the sprite

	bool checkCollision(std::vector<Obj_MainParent*>, int, int);

	//Getters and Setters

	void setActive(bool);

	Collider* getCollider();

	int getX();

	int getY();

	int getWidth();

	int getHeight();

	int getId();

	bool getSolid();

};

/*------------------------------------
//The player object
*/
class Obj_Player: public Obj_MainParent
{
public:
	Obj_Player(int, SDL_Renderer*, int, int);                                    //Constructor

	void update(EventHandler, GameTime, std::vector<Obj_MainParent*>);           //The update function, runs each frame

	int speed;

	bool wKey;
	bool aKey;
	bool sKey;
	bool dKey;

	float xMovement;
	float yMovement;

	bool canMoveX;
	bool canMoveY;

};

/*------------------------------------
//A wall
*/
class Obj_Wall : public Obj_MainParent
{
public:
	Obj_Wall(int, SDL_Renderer*, int, int);             //Constructor

	void update(EventHandler, GameTime, std::vector<Obj_MainParent*>);           //The update function, runs each frame

};