#include "Objects.h"

Obj_Wall::Obj_Wall(SDL_Renderer* renderer, int startX, int startY)
	:Obj_MainParent(renderer, startX, startY)
{
	sprite = new Sprite(renderer, "resources/img.png", 150, 150, 1, 0.0f);
}

void Obj_Wall::update(EventHandler e, GameTime t)
{
	
}