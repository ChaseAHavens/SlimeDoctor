#include "entity.h"

entity::entity(std::string name):
	theName(name)
{
	isMask = false;
	theColor = { 0, 0, 0, 255 };
}
entity::entity(std::string name, int id , int x, int y, int h, int w, int z) :
	theName(name), imageId(id)
{
	setPos(x, y);
	setSize(h, w);
	setZ(z);
	isMask = false;
	theColor = { 0, 0, 0, 255 };
}
entity::~entity()
{}

void entity::setPos(int x, int y)
{
	tx.x = x;
	tx.y = y;
}
void entity::setSize(int h, int w)
{
	tx.h = h;
	tx.w = w;
}


SDL_Rect entity::posAScaleB(SDL_Rect a, SDL_Rect b)//static
{
	SDL_Rect temp = { a.x, a.y, b.h, b.w };
	return temp;
}