#include "Sprite.h"

using namespace std;

Sprite::Sprite(SDL_Renderer* rendererIn, std::string file, 
	int frameWidthIn, int frameHeightIn, int framesIn, float speedIn)
{
	frames = framesIn;
	frame = 0;
	renderer = rendererIn;
	speed = speedIn;
	speedCounter = 0.0f;

	frameWidth = frameWidthIn;
	frameHeight = frameHeightIn;

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
			rects[counter].x = j*frameWidthIn;
			rects[counter].y = i*frameHeightIn;
			rects[counter].w = frameWidthIn;
			rects[counter].h = frameHeightIn;
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

void Sprite::update(GameTime t)
{
	if (speedCounter >= (1.0f / speed))
	{
		frame += 1;
		if (frame >= frames)
			frame = 0;
		speedCounter = 0.0f;
	}
	else
	{
		speedCounter += t.getDeltaTime();
	}
}

void Sprite::nextFrame()
{
	frame += 1;
	if (frame >= frames)
		frame = 0;
}

//Getters and Setters

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

void Sprite::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

float Sprite::getSpeed()
{
	return speed;
}

int Sprite::getWidth()
{
	return frameWidth;
}

int Sprite::getHeight()
{
	return frameHeight;
}