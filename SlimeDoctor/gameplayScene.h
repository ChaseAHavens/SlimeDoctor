#pragma once
#include "timer.h"
#include <SDL.h>
#include <math.h>
#include "entities.h"
#include "entity.h"

class gameplayScene
{
public:
	gameplayScene();
	~gameplayScene();

	void setup();
	void step(float delta);
	

	bool getE(entities* ent);
	
	float slimeBounceH();
	float slimeBounceW();
	timer slimeBounce;
	int slimeBounceAmount;

private:
	entities * e;

	float slimeY;
	float slimeX;
	float slimeH;
	float slimeW;


	//slime
	entity* shell;
	entity* inner;
	entity* eyes;
	entity* shine;
	entity* table;

};