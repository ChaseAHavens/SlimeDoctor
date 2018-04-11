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
		makeSTARTUPEntities();
		g = SPLASH_SCREEN;
		break;
	case SPLASH_SCREEN:
		updateScreen();
		break;
	case GAME_LOAD_SCENE_1:
		break;
	case GAME_SCENE_1:
		break;

	}
}
void game::updateScreen()
{
	SDL_RenderClear(v->theRenderer);
	for (std::pair<std::string,entity> p : e.e)
	{
		int imageId = p.second.imageId;
		v->blit(imageId, p.second.getX(), p.second.getY());

	}
	v->updateScreen();

}
void game::createEntity(std::string name) 
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
	return false;
}
void game::makeSTARTUPEntities()
{
	int tmp = v->addImage("images/splashPage.png");
	image* tmpI = v->imageById(tmp);
	e.makeEntity("splashPage", tmp, tmpI->theRect.x, tmpI->theRect.y, tmpI->theRect.h, tmpI->theRect.w);
}