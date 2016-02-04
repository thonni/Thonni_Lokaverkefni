#include "EventHandler.h"
#include <iostream>

using namespace std;

EventHandler::EventHandler()
{
	keyDown = NULL;
	a = false;
}

//A function that runs each frame, and updates things like keys down
//and the events list.
void EventHandler::update()
{
	//Set lastKeysDown to the last key list
	for (int i = 0; i < 6; i++)
	{
		lastKeysDown[i] = keysDown[i];
	}
	std::fill_n(events, 48, 0);
	j = 0;
	//Loop trough events types
	while (SDL_PollEvent(&e) != 0)
	{
		events[j] = e.type;
		switch (e.type)
		{
		//Key Down Event (Puts keys that are down in an array)
		case SDL_KEYDOWN:
			a = false;
			for (int i = 0; i < 6; i++)
			{
				if (keysDown[i] == e.key.keysym.sym)
					a = true;
			}
			if (a)
				break;
			for (int i = 0; i < 6; i++)
			{
				if (keysDown[i] == e.key.keysym.sym)
					break;
				if (keysDown[i] == 0)
				{
					keysDown[i] = e.key.keysym.sym;
					break;
				}
					
			}
			break;

		//Key up event (Takes keys that go up out of the array)
		case SDL_KEYUP:
			for (int i = 0; i < 6; i++)
			{
				if (keysDown[i] == e.key.keysym.sym)
				{
					keysDown[i] = 0;
				}
					
			}
			break;
		}
	}
}

// TODO: LAGA
bool EventHandler::getEvent(Uint32 event)
{
	a = false;
	for (int i = 0; i < 48; i++)
	{
		if (events[i] == event)
			a = true;
	}
	
	if (a)
		return true;
	else
		return false;

}

bool EventHandler::getKeyHeld(SDL_Keycode key)
{
	keyDown = false;
	for (int i = 0; i < 6; i++)
	{
		if (keysDown[i] == key)
			keyDown = true;
	}

	return keyDown;
}

bool EventHandler::getKeyPressed(SDL_Keycode key)
{
	keyDown = false;
	for (int i = 0; i < 6; i++)
	{
		if (keysDown[i] == key)
			keyDown = true;
	}
	for (int i = 0; i < 6; i++)
	{
		if (lastKeysDown[i] == key)
			keyDown = false;
	}

	return keyDown;
}