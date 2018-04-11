#include "game.h"

game::game() :
	fps(60), tpf(1000.0f/60), g(STARTUP)
{
	frameCap.start();
	deltaTimer.start();
}
game::~game()
{}

void game::step(float delta)
{
	switch (g)
	{
	case STARTUP:

		break;
	case SPLASH_SCREEN:
		break;
	case GAME_LOAD_SCENE_1:
		break;
	case GAME_SCENE_1:
		break;

	}
}
void game::updateScreen()
{

}
void game::createEntity(std::string name, ) 
{
	if ( eList.find(name) != eList.end())
	{
		eList[name];
	}

}
void game::maxFpsDelay()
{
	float t = (float)frameCap.getTicks();
	if (t < tpf) 
	{
		Uint32 tempA = frameCap.getTicks();
		float tempB = tpf - (float)tempA;
			SDL_Delay(tempB);
			frameCap.start();
	}
}

float game::deltaTime()
{
	float delta = deltaTimer.getTicks() / 1000.f;
	deltaTimer.start();
	return delta;
}
bool game::loadImages()
{

}