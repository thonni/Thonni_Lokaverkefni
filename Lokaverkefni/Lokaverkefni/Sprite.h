#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "string"
#include "iostream"
#include "vector"
#include "GameTime.h"

using namespace std;

class Sprite
{
protected:

	int frame;                  //Current frame of the texture

	int frames;                 //Number of frames the sprite has

	int baseTextureWidth;       //The width of the whole texture

	int baseTextureHeight;      //The height of the whole texture

	int counter;                //A counter that helps with mapping the frames on the texture

	float speed;                //The speed of the texture changing frames

	float speedCounter;         //A float that counts until to change the frame

	SDL_Texture* baseTexture;   //The texture/image that the sprite uses

	SDL_Renderer* renderer;     //The renderer that passes to the sprite function

	vector<SDL_Rect> rects;     //A vector list that maps out each frame on the texture

	SDL_Rect tempRect;

public:
	Sprite(SDL_Renderer* renderer, std::string file, 
		   int frameWidth, int frameHeight, const int frames, float speedIn);

	void render(int, int);     //Draws the current frame on screen

	void update(GameTime t);   //Updates the sprite class, should run each frame

	void nextFrame();          //Changes to the next frame

	//Getters and Setters
	int setFrame(int);         //Set frame

	void setSpeed(float);      //Set speed
	float getSpeed();          //Get speed

};

