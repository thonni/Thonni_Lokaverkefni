#include "Sprite.h"

using namespace std;

Sprite::Sprite(SDL_Renderer* rendererIn, std::string file, 
	int frameWidth, int frameHeight, int framesIn)
{
	frames = framesIn;
	frame = 0;
	renderer = rendererIn;

	baseTexture = NULL;

	rects.resize(frames);

	SDL_Surface* loadedSurface = IMG_Load(file.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load the image! SDL_image Error: %s\n", file.c_str(), IMG_GetError());
	}
	else
	{
		baseTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

		SDL_FreeSurface(loadedSurface);
	}

	SDL_QueryTexture(baseTexture, NULL, NULL, &baseTextureWidth, &baseTextureHeight);

	counter = 0;
	for (int i = 0; i < baseTextureHeight / frameHeight; i++)
	{
		for (int j = 0; j < baseTextureWidth / frameWidth; j++)
		{
			rects[counter].x = j*frameWidth;
			rects[counter].y = i*frameHeight;
			rects[counter].w = frameWidth;
			rects[counter].h = frameHeight;
			counter++;
			if (counter >= frames)
				break;
		}
		if (counter >= frames)
			break;
	}
}

void Sprite::render(int x, int y)
{
	tempRect = { x,y,rects[frame].w, rects[frame].h };
	SDL_RenderCopy(renderer, baseTexture, &rects[frame], &tempRect);
}

void Sprite::update()
{
	frame += 1;
	if (frame >= frames)
		frame = 0;
}

int Sprite::setFrame(int frameIn)
{
	if (frameIn < frames && frameIn >= 0)
	{
		frame = frameIn;
		return true;
	}
	else
	{
		return false;
	}
}

void Sprite::nextFrame()
{
	frame += 1;
	if (frame >= frames)
		frame = 0;
}