#pragma once

#include "SDL.h"


/*
//This class handles all events, for example keyboard input
*/
class EventHandler
{
private:
	SDL_Event e;                                     //Holds the main event object that is used by many classes

	bool keyDown;                                    //Bool used to return true or false

	SDL_Keycode keysDown[6] = { 0,0,0,0,0,0 };       //List of keys down, can hold six keys at a time

	SDL_Keycode lastKeysDown[6] = { 0,0,0,0,0,0 };   //List of keys down last frame

	Uint32 events[48];                               //Holds all events active, like key down or mouse movement

	bool a;

	int j;

public:
	EventHandler();                                  //Constructor

	void update();                                   //Updates the class, runs each frame

	bool getEvent(Uint32);                           //Checks if the given event is active, and returns true or false

	bool getKeyHeld(SDL_Keycode);                    //Checks if the given key is HELD down and returns true or false

	bool getKeyPressed(SDL_Keycode);                 //Checks if the given key is pressed once, returns true only for one frame

};

