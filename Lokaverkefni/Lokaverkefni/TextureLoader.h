#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "stdio.h"
#include "string"

class TextureLoader
{
private:

public:
	SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string file)
	{
		SDL_Texture* newTexture = NULL;

		SDL_Surface* loadedSurface = IMG_Load(file.c_str());

		if (loadedSurface == NULL)
		{
			printf("Unable to load the image! SDL_image Error: %s\n", file.c_str(), IMG_GetError());
		}
		else
		{
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	}

};