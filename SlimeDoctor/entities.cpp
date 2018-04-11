#include "entities.h"

entities::entities()
{}
entities::~entities()
{}

void entities::makeEntity(std::string name, int imageId, int x, int y, int h, int w)
{
	if (e.find(name) == e.end())
	{
		e[name].setImageId(imageId);
		e[name].setPos(x, y);
		e[name].setSize(h, w);
	}
}
void entities::deleteEntity(std::string name)
{
	if (e.find(name) != e.end())
	{
		e.erase(name);
	}
}

void entities::clearAllEntities()
{
	e.clear();
}

entity entities::get(std::string name)
{
	if (e.find(name) != e.end())
	{
		return e[name];
	}
	else
	{
		return entity();
	}
}