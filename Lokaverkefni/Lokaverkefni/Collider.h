#pragma once
class Collider
{
private:
	int deltaX;

	int deltaY;

	int width;

	int height;

	bool solid;
public:
	Collider(int deltaXIn, int deltaYIn, int widthIn, int heightIn);

	//Getters and Setters

	void setX(int xIn);

	void setY(int yIn);

	void setWidth(int widthIn);

	void setHeight(int heightIn);

	int getX();

	int getY();

	int getWidth();

	int getHeight();

};

