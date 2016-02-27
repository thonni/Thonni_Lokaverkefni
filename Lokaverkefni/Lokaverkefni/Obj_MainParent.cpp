#include "Objects.h"


Obj_MainParent::Obj_MainParent(int idIn, SDL_Renderer* rendererIn, int startX, int startY)
{	
	renderer = rendererIn;
	x = startX;
	y = startY;
	
	visible = true;
	active = true;
	
	id = idIn;

	setSprite("resources/default.png", 64, 64, 1, 0.0f);
}

void Obj_MainParent::mainUpdate(EventHandler e, GameTime t, std::vector<Obj_MainParent*> o)
{
	if (active)
	{
		sprite->update(t);
		update(e, t, o);
	}
}

void Obj_MainParent::update(EventHandler e, GameTime t, std::vector<Obj_MainParent*> o) {};

void Obj_MainParent::render(int deltaX, int deltaY)
{
	if(visible && active)
		sprite->render((x+deltaX), (y+deltaY));
}

void Obj_MainParent::setSprite(std::string file, int frameWidth, int frameHeight, int frames, float speed)
{
	delete sprite;
	sprite = new Sprite(renderer, file, frameWidth, frameHeight, frames, speed);
	width = sprite->getWidth();
	height = sprite->getHeight();
	collider = new Collider(0, 0, width, height);
}

bool Obj_MainParent::checkCollision(std::vector<Obj_MainParent*> o, int deltaX, int deltaY)
{
	bool collision = false;
	for (int i = 0; i < o.size(); i++)
	{
		if (o[i]->getId() != id && o[i]->getSolid())
		{
			if ((((x + deltaX) < (o[i]->getX() + o[i]->getWidth())) && ((x + width + deltaX) > (o[i]->getX())))
				&& (((y + deltaY) < (o[i]->getY() + o[i]->getHeight())) && ((y + height + deltaY) > (o[i]->getY()))))
			{
				collision = true;
			}
			
			return !collision;
		}
	}
}

//Getters and Setters

void Obj_MainParent::setActive(bool in)
{
	active = in;
}

Collider* Obj_MainParent::getCollider() { return collider; }

int Obj_MainParent::getX() { return x; }

int Obj_MainParent::getY() { return y; }

int Obj_MainParent::getId() { return id; }

int Obj_MainParent::getWidth() { return width; }

int Obj_MainParent::getHeight() { return height; }

bool Obj_MainParent::getSolid() { return solid; }