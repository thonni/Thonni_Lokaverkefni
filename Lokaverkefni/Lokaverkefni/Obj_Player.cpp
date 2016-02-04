#include "Objects.h"


Obj_Player::Obj_Player(SDL_Renderer* renderer, int startX, int startY)
	:Obj_MainParent(renderer, startX, startY)
{
	setTexture("resources/img.png");
}

void Obj_Player::update(EventHandler e, GameTime t)
{
	if(e.getKeyPressed(SDLK_e))
		setTexture("resources/img.png");

	if (e.getKeyHeld(SDLK_d))
		x += 50*t.getDeltaTime();
	if (e.getKeyHeld(SDLK_a))
		x -= 50 * t.getDeltaTime();
	if (e.getKeyHeld(SDLK_w))
		y -= 50 * t.getDeltaTime();
	if (e.getKeyHeld(SDLK_s))
		y += 50 * t.getDeltaTime();

	if (e.getKeyPressed(SDLK_r))
		sprite->nextFrame();
}