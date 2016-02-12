#pragma once

#include "SDL.h"

class GameTime
{
private:
	float deltaTime;         //Holds the time that passes between frames

	long currentTime;        //Holds the current time

	long lastTime;           //Holds the time last frame (Both used to get delta time)

public:
	GameTime();				 //Initializer

	void update();			 //Runs each frame to update the time

	//Getters and Setters
	double getDeltaTime();   //Returns Delta Time

};

