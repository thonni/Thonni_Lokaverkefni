#include "Objects.h"


Obj_MainParent::Obj_MainParent(SDL_Renderer* rendererIn, int startX, int startY)
{
	renderer = rendererIn;
	x = startX;
	y = startY;
	
	solid = false;
	visible = true;
	active = true;

	setSprite("resources/default.png", 64, 64, 1, 0.0f);
}

void Obj_MainParent::mainUpdate(EventHandler e, GameTime t)
{
	if (active)
	{
		sprite->update(t);
		update(e, t);
	}
}

void Obj_MainParent::update(EventHandler e, GameTime t) {};

void Obj_MainParent::render(int deltaX, int deltaY)
{
	if(visible && active)
		sprite->render((x+deltaX), (y+deltaY));
}

void Obj_MainParent::setSprite(std::string file, int frameWidth, int frameHeight, int frames, float speed)
{
	sprite = new Sprite(renderer, file, frameWidth, frameHeight, frames, speed);
	width = sprite->getWidth();
	height = sprite->getHeight();
}

//Getters and Setters

void Obj_MainParent::setActive(bool in)
{
	active = in;
}