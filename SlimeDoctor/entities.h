#pragma once
#include <map>
#include <string>
#include "entity.h"

class entities
{
public:
	entities();
	~entities();

	void makeEntity(std::string name, int imageId, int x, int y, int h, int w);
	void deleteEntity(std::string name);

	void clearAllEntities();

	entity get(std::string name);


	std::map<std::string, entity> e;


};