#include "entities.h"

entities::entities()
{}
entities::~entities()
{}

void entities::makeEntity(std::string name, int id, int x, int y, int h, int w, int z)
{

	if (nameExists(name))
	{
		std::cout << "Trying to create Entity that already exists" << std::endl;
	}
	else
	{
		e.push_back(entity(name, id, x, y, h, w, z));
	}
	/*
	if (e.find(name) == e.end())
	{
		e[name].setImageId(imageId);
		e[name].setPos(x, y);
		e[name].setSize(h, w);
		e[name].setZ(z);
	}
	//*/
}
void entities::deleteEntity(std::string name)
{
	if (nameExists(name))
	{
		std::vector<entity>::iterator it = (e.begin() + getVecPos(name));
		e.erase(it);
	}
	else
	{
		std::cout << "Trying to erase entity by name that doesnt exist" << std::endl;
	}
	/*
	if (e.find(name) != e.end())
	{
		e.erase(name);
	}*/
}

void entities::clearAllEntities()
{
	e.clear();
}

entity entities::get(std::string name)
{
	entity ret = entity();//bad way to do this, returning empty when none exists
	if (nameExists(name))
	{
		ret = e.at(getVecPos(name));

	}
	else 
	{
		std::cout << "Trying to get entity by name that doesnt exist" << std::endl;
	}
	return ret;
	/*
	if (e.find(name) != e.end())
	{
		return e[name];
	}
	else
	{
		return entity();
	}*/
}
int entities::getVecPos(std::string name)
{
	int retVal = -1;
	if (nameExists(name))
	{
		int entCount = e.size();
		int curEnt = 0;
		while (curEnt < entCount)
		{
			if (e.at(curEnt).getName() == name)
			{
				retVal = curEnt;
				break;
			}
			curEnt++;
		}
	}
	else
	{
		std::cout << "Trying to get entity by name that doesnt exist" << std::endl;
	}
	return retVal;
}
bool entities::nameExists(std::string name)
{
	bool exists = false;
	int entCount = e.size();
	int curEnt = 0;
	while (curEnt < entCount)
	{
		if (e.at(curEnt).getName() == name)
		{
			exists = true;
			break;
		}
		curEnt++;
	}
	return exists;
}
void entities::sortByZ() 
{
	std::sort(e.begin(), e.end(), [](int a, int b) { return a > b;} );
}