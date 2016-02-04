#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "TextureLoader.h"
#include "string"
#include "EventHandler.h"
#include "Sprite.h"
#include "GameTime.h"

class Obj_MainParent
{
protected:
	SDL_Texture* texture;
	SDL_Rect imageRectangle;
	SDL_Renderer* renderer;
	TextureLoader textureLoader;
	SDL_Point position;
	float x;
	float y;
	Sprite* sprite;

public:
	Obj_MainParent(SDL_Renderer*, int, int);
	void mainUpdate(EventHandler, GameTime);
	virtual void update(EventHandler, GameTime);
	void render();
	void setTexture(std::string);
};

class Obj_Player: public Obj_MainParent
{
public:
	Obj_Player(SDL_Renderer*, int, int);
	void update(EventHandler, GameTime);
};