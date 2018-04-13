#pragma once
#include <vector>
#include <string>
#include "entity.h"
#include <iostream>
#include <algorithm>

class entities
{
public:
	entities();
	~entities();

	void makeEntity(std::string name, int imageId, int x, int y, int h, int w, int z);
	void deleteEntity(std::string name);

	bool nameExists(std::string name);

	void clearAllEntities();

	entity& get(std::string name);
	int getVecPos(std::string name);
	void sortByZ();
	std::vector<entity> e;


};