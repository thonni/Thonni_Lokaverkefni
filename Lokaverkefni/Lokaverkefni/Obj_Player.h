#pragma once

#include "Obj_ParentMain.h"
#include "TextureLoader.h"
#include "SDL.h"
#include "SDL_image.h"
#include "iostream"

using namespace std;

class Obj_Player: public Obj_ParentMain
{
private:
	int a;

public:
	Obj_Player(SDL_Event &eIn, SDL_Renderer* rendererIn, int startX, int startY)
		:Obj_ParentMain(eIn, rendererIn, startX, startY)
	{
		texture = NULL;
		texture = textureLoader.loadTexture(renderer, "resources/img.png");

		a = 0;
	}

	void update()
	{
		if (e.key.keysym.sym == SDLK_w)
		{
			//position.y -= 1;
			printf("hnegg\n");
		}
	}

};