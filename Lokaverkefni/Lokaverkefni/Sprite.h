#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Sprite
{
protected:

	int frame;

	int frames;

	SDL_Texture* baseTexture;

	int baseTextureWidth;

	int baseTextureHeight;

	int counter;

	SDL_Renderer* renderer;

	vector<SDL_Rect> rects;

	SDL_Rect tempRect;

public:
	Sprite(SDL_Renderer* renderer, std::string file, 
		   int frameWidth, int frameHeight, const int frames);

	void render(int, int);

	void update();

	int setFrame(int);

	void nextFrame();

};

