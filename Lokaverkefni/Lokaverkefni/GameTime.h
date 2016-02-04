#pragma once

#include "SDL.h"

class GameTime
{
private:
	float deltaTime;
	long currentTime;
	long lastTime;

public:
	GameTime();
	void update();

	//Getters and Setters
	double getDeltaTime();

};

