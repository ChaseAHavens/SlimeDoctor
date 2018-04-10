#include "image.h"

image::image(SDL_Surface* theI)
{
	setImage(theI);
}

image::~image()
{
	//SDL_FreeSurface(theImage); //was deleting surface after copys
	theImage = NULL;

}

void image::setImage(SDL_Surface* theI)
{
	theImage = theI;
	theHeight = theImage->h;
	theWidth = theImage->w;
}
