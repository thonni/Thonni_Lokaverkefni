#pragma once
#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "TextureLoader.h"

class Obj_ParentMain
{

protected:
	SDL_Point position;
	SDL_Texture* texture;
	SDL_Rect imageRectangle;

	SDL_Renderer* renderer;
	SDL_Event e;
	TextureLoader textureLoader;

public:
	Obj_ParentMain(SDL_Event &eIn, SDL_Renderer* rendererIn, int startX, int startY)
	{
		position.x = startX;
		position.y = startY;
		imageRectangle.x = position.x;
		imageRectangle.y = position.y;

		imageRectangle.h = 150;
		imageRectangle.w = 150;

		renderer = rendererIn;
		e = eIn;

		texture = textureLoader.loadTexture(renderer, "resources/default.png");
	}

	void mainUpdate()
	{

		imageRectangle.x = position.x;
		imageRectangle.y = position.y;

		update();
	}

	virtual void update() {};

	void render(SDL_Rect region)
	{
		SDL_RenderCopy(renderer, texture, &region, &imageRectangle);
	}

	//Getters and Setters
	SDL_Point getPosition()
	{
		return position;
	}

};