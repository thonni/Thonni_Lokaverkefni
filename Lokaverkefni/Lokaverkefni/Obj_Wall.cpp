#include "Objects.h"

Obj_Wall::Obj_Wall(int idIn, SDL_Renderer* renderer, int startX, int startY)
	:Obj_MainParent(idIn, renderer, startX, startY)
{
	setSprite("resources/block.png", 32, 32, 1, 0.0f);
	solid = true;
}

void Obj_Wall::update(EventHandler e, GameTime t, std::vector<Obj_MainParent*> o)
{
	
}