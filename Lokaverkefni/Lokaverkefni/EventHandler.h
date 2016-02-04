#pragma once

#include "SDL.h"

class EventHandler
{
private:
	SDL_Event e;
	bool keyDown;
	SDL_Keycode keysDown[6] = { 0,0,0,0,0,0 };
	SDL_Keycode lastKeysDown[6] = { 0,0,0,0,0,0 };
	Uint32 events[48];
	bool a;
	int j;

public:
	EventHandler();
	void update();
	bool getEvent(Uint32);
	bool getKeyHeld(SDL_Keycode);
	bool getKeyPressed(SDL_Keycode);

};

