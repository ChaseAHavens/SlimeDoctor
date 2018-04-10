#pragma once
#include <SDL.h>


class image
{
public:
	image(SDL_Texture* theI, int h, int w);
	image() {};
	~image();

	void setImage(SDL_Texture* theI); //inintal setting of image and to change, maybe for scaling later
	
	SDL_Texture* theImage;
	SDL_Rect theRect;
	int theHeight;
	int theWidth;


};