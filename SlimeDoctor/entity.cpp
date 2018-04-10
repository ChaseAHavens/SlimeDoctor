#include "entity.h"

entity::entity()
{}
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