#include "Objects.h"


Obj_Player::Obj_Player(SDL_Renderer* renderer, int startX, int startY)
	:Obj_MainParent(renderer, startX, startY)
{
	sprite = new Sprite(renderer, "resources/mario.png", 16, 28, 4, 0.1f);
}

void Obj_Player::update(EventHandler e, GameTime t)
{
	if (e.getKeyHeld(SDLK_d))
		x += 50*t.getDeltaTime();
	if (e.getKeyHeld(SDLK_a))
		x -= 50 * t.getDeltaTime();
	if (e.getKeyHeld(SDLK_w))
		y -= 50 * t.getDeltaTime();
	if (e.getKeyHeld(SDLK_s))
		y += 50 * t.getDeltaTime();

	if (e.getKeyPressed(SDLK_r))
		sprite->setSpeed(sprite->getSpeed() + 0.1f);
}