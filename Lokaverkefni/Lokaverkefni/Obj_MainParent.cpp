#include "Objects.h"


Obj_MainParent::Obj_MainParent(SDL_Renderer* rendererIn, int startX, int startY)
{
	renderer = rendererIn;
	x = startX;
	y = startY;
	
	sprite = new Sprite(renderer, "resources/default.png", 64, 64, 1, 0.0f);
}

void Obj_MainParent::mainUpdate(EventHandler e, GameTime t)
{
	sprite->update(t);
	update(e, t);
}

void Obj_MainParent::update(EventHandler e, GameTime t) {};

void Obj_MainParent::render(int deltaX, int deltaY)
{
	sprite->render((x+deltaX), (y+deltaY));
}