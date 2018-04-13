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

entity& entity::setPos(int x, int y)
{
	tx.x = x;
	tx.y = y;
	return *this;
}
entity& entity::setSize(int h, int w)
{
	tx.h = h;
	tx.w = w;
	return *this;
}
entity& entity::setZ(int z) 
{
	theZ = z; 
	return *this;
}
entity& entity::setVisable(bool vis) 
{
	isVisable = vis; 
	return *this;
}
entity& entity::setImageId(int id) 
{ 
	imageId = id;
	return *this;
}

entity& entity::setMask(bool mask)
{
	isMask = mask;
	return *this;
}
entity& entity::setColor(SDL_Color col)
{
	theColor = col;
	return *this;
}

SDL_Rect entity::posAScaleB(SDL_Rect a, SDL_Rect b)//static
{
	SDL_Rect temp = { a.x, a.y, b.h, b.w };
	return temp;
}