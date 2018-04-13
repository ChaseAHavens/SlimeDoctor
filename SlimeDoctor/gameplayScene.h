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
	timer slimeTime;
	int slimeBounceAmount;
	int slimeBlinkDelay;

	enum eyesState
	{
		OPEN,
		BLINK1,
		BLINK2,
		SAD
	};

private:
	eyesState eS;

	entities * e;

	float slimeY;
	float slimeX;
	float slimeH;
	float slimeW;


	//slime
	entity* shell;
	entity* inner;
	entity* eyes;
	entity* eyes1;
	entity* eyes2;
	entity* eyesSad;
	entity* shine;
	entity* table;


	void setupSlime();
	void animateBounce();
	void animateBlink();
	void slimeChangeEyes();
};