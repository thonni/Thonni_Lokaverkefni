#pragma once

#include "SDL.h"

class Camera
{

private:
	SDL_Point position;
	SDL_Texture* texture;

public:
	Camera(int startX, int startY)
	{
		position.x = startX;
		position.y = startY;
	}

	//Getters and setters
	SDL_Point getPosition()
	{
		return position;
	}
		
};