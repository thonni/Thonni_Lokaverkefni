#include "Objects.h"


Obj_Player::Obj_Player(int idIn, SDL_Renderer* renderer, int startX, int startY)
	:Obj_MainParent(idIn, renderer, startX, startY)
{
	setSprite("resources/mario.png", 16, 28, 4, 2.0f);

	xMovement = 0;
	yMovement = 0;

	speed = 50;
}

void Obj_Player::update(EventHandler e, GameTime t, std::vector<Obj_MainParent*> o)
{
	
	wKey = e.getKeyHeld(SDLK_w);
	aKey = e.getKeyHeld(SDLK_a);
	sKey = e.getKeyHeld(SDLK_s);
	dKey = e.getKeyHeld(SDLK_d);
	
	xMovement = 0;
	yMovement = 0;

	if (wKey)
		yMovement -= (speed*t.getDeltaTime());
	if (aKey)
		xMovement -= (speed*t.getDeltaTime());
	if (sKey)
		yMovement += (speed*t.getDeltaTime());
	if (dKey)
		xMovement += (speed*t.getDeltaTime());

	canMoveX = true;
	canMoveY = true;
	/*for (int i = 0; i < o.size(); i++)
	{
		if (o[i]->getId() != id && o[i]->getSolid())
		{
			if ((((x + xMovement) < (o[i]->getX() + o[i]->getWidth())) && ((x + width + xMovement) > (o[i]->getX())))
				&& (((y + yMovement) < (o[i]->getY() + o[i]->getHeight())) && ((y + height + yMovement) > (o[i]->getY()))))
			{
				if ((((x + xMovement) < (o[i]->getX() + o[i]->getWidth())) && ((x + width + xMovement) > (o[i]->getX()))))
					canMoveX = false;
				if ((((y + yMovement) < (o[i]->getY() + o[i]->getHeight())) && ((y + height + yMovement) > (o[i]->getY()))))
					canMoveY = false;
			}
		}
	}*/

	if (checkCollision(o, xMovement, yMovement))
		x += xMovement;
		y += yMovement;
	//if (checkCollision(o, 0, yMovement))
	//	y += yMovement;

	if (e.getKeyPressed(SDLK_r))
	{
		if (visible)
			visible = false;
		else
			visible = true;
	}
}