#pragma once
#include <SDL.h>
#include "video.h"
#include "entity.h"
#include "entities.h"
#include "image.h"
#include "timer.h"
#include <vector>
#include <string>
#include "gameplayScene.h"


///TODO: move video class into game class to be able to easily change resolution
class game
{
public:
	game();
	~game();

	void step(float delta);
	void updateScreen();

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

	gameplayScene gameplay;

	SDL_Event event;
	entities e;
	//std::vector<entity> eList;
	gameMode g;
	timer deltaTimer;
	const float tpf;
	const Uint32 fps;
};
