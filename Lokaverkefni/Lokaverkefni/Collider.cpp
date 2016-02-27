#include "Collider.h"



Collider::Collider(int deltaXIn, int deltaYIn, int widthIn, int heightIn)
{
	deltaX = deltaXIn;
	deltaY = deltaYIn;

	width = widthIn;
	height = heightIn;

	solid = false;
}

//Getters and Setters

void Collider::setX(int xIn) { deltaX = xIn; }

void Collider::setY(int yIn) { deltaY = yIn; }

void Collider::setWidth(int widthIn) { width = widthIn; }

void Collider::setHeight(int heightIn) { height = heightIn; }

int Collider::getX() { return deltaX; }

int Collider::getY() { return deltaY; }

int Collider::getWidth() { return width; }

int Collider::getHeight() { return height; }