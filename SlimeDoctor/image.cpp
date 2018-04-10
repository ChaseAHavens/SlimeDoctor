#include "image.h"

image::image(SDL_Surface* theI, int id):
	 idNumber(id)
{
	setImage(theI);
}

image::~image()
{
	SDL_FreeSurface(theImage);
	theImage = NULL;

}

void image::setImage(SDL_Surface* theI)
{
	theImage = theI;
	theHeight = theImage->h;
	theWidth = theImage->w;
}
