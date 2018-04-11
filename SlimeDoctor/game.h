#pragma once
#include <SDL.h>
#include "video.h"
#include "entity.h"
#include "entities.h"
#include "image.h"
#include "timer.h"
#include <map>
#include <string>

class game
{
public:
	game();
	~game();

	void step(float delta);
	void updateScreen();

	void maxFpsDelay();

	video* v;

	float deltaTime();
	
	void createEntity(std::string name);

	enum gameMode
	{
		STARTUP,
		SPLASH_SCREEN,
		GAME_LOAD_SCENE_1,
		GAME_SCENE_1,

		QUIT
	};


	void input();
	bool quit;
private:
	void makeSTARTUPEntities();
	void makeGAMEEntities();

	SDL_Event event;
	entities e;
	std::map<std::string, entity> eList;
	gameMode g;
	bool loadImages();
	timer deltaTimer;
	timer frameCap;
	const float tpf;
	const Uint32 fps;
};
