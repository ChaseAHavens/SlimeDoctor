#pragma once
#include <SDL.h>

class image
{
public:
	image(SDL_Surface* theI, int id);
	~image();

	void setImage(SDL_Surface* theI); //inintal setting of image and to change, maybe for scaling later
	
	SDL_Surface* theImage;
	int idNumber;
	int theHeight;
	int theWidth;


};