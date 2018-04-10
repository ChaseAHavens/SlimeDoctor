#include "image.h"

image::image(SDL_Texture* theI, int h, int w):
	theHeight(h), theWidth(w)
{
	setImage(theI);
	theRect.h = h;
	theRect.w = w;
	theRect.x = 0;
	theRect.y = 0;
}

image::~image()
{
	//SDL_FreeSurface(theImage); //was deleting surface after copys
	theImage = NULL;

}

void image::setImage(SDL_Texture* theI)
{
	theImage = theI;
}
