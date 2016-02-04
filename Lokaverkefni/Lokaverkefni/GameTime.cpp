#include "GameTime.h"

#include "iostream"

GameTime::GameTime()
{
	deltaTime = 0.0f;
	currentTime = 0;
	lastTime = 0;
}

void GameTime::update()
{
	currentTime = SDL_GetTicks();

	if (currentTime > lastTime)
	{
		deltaTime = ((float)(currentTime-lastTime))/1000;
		lastTime = currentTime;
	}
}

//Getters and Setters
double GameTime::getDeltaTime() { return deltaTime; };

