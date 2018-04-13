#include "game.h"

game::game() :
	fps(60), tpf(1000.0f/60), g(STARTUP), quit(false)
{
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
		SDL_Delay(200);
		g = GAME_LOAD_SCENE_1;
		break;
	case GAME_LOAD_SCENE_1:
		e.clearAllEntities();
		makeGAMEEntities();
		gameplay.setup();
		g = GAME_SCENE_1;
		break;
	case GAME_SCENE_1:
		gameplay.step(delta);
		updateScreen();
		input();
		break;
	case QUIT:

		break;
	}
}
void game::updateScreen()
{
	SDL_RenderClear(v->theRenderer);
	int entCount = e.e.size();
	int curEnt = 0;
	entity* tmpEnt;
	while (curEnt < entCount)
	{
		tmpEnt = &e.e.at(curEnt);
		int imageId = tmpEnt->getImageId();//e.e.at(curEnt).getImageId();
		if (tmpEnt->getVis()) {
			v->blit(imageId, tmpEnt->getX(), tmpEnt->getY(), tmpEnt->getH(), tmpEnt->getW());
		}
		curEnt++;
	}
	v->updateScreen();
}
void game::createEntity(std::string name) //does this do anything?
{
	//if ( eList.find(name) != eList.end())
	{
		//eList[name];
	}

}


float game::deltaTime()
{
	float delta = deltaTimer.getTicks() / 1000.f;
	deltaTimer.start();
	return delta;
}
void game::makeSTARTUPEntities()
{
	int tmp = v->addImage("images/splashPage.png");
	image* tmpI = v->imageById(tmp);
	e.makeEntity("splashPage", tmp, tmpI->theRect.x, tmpI->theRect.y, tmpI->theRect.h, tmpI->theRect.w, 10);
}
void game::makeGAMEEntities()
{
	gameplay.getE(&e);
	int tmp;
	image* tmpI;
	SDL_Color tempCol;
	entity tmpEnt;

	///table
	tmp = v->addImage("images/table.png");
	tmpI = v->imageById(tmp);
	e.makeEntity("table", tmp, tmpI->theRect.x, tmpI->theRect.y, tmpI->theRect.h, tmpI->theRect.w, 9);
	tmpEnt = e.get("table");
	tmpEnt.setVisable(true).setMask(false);
	///shell 
	tempCol = { 10, 222, 10, 199 };
	tmp = v->generateFromMask("images/mask/slimeShell.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("shell", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 7);
	tmpEnt = e.get("shell");
	tmpEnt.setVisable(true).setMask(true).setColor(tempCol);
	///inner
	tempCol = { 20, 222, 20, 60 };
	tmp = v->generateFromMask("images/mask/slimeInner.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("inner", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 8);
	tmpEnt = e.get("inner");
	tmpEnt.setVisable(true).setMask(true).setColor(tempCol);
	///eyesOpen
	tempCol = { 10, 25, 10, 200 };
	tmp = v->generateFromMask("images/mask/slimeEyes.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("eyes", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	tmpEnt = e.get("eyes");
	tmpEnt.setVisable(true).setMask(true).setColor(tempCol);
	///eyesBlink0
	tempCol = { 10, 25, 10, 200 };
	tmp = v->generateFromMask("images/mask/slimeEyes1.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("eyes1", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	tmpEnt = e.get("eyes1");
	tmpEnt.setVisable(false).setMask(true).setColor(tempCol);
	///eyesBlink1
	tempCol = { 10, 25, 10, 200 };
	tmp = v->generateFromMask("images/mask/slimeEyes2.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("eyes2", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	tmpEnt = e.get("eyes2");
	tmpEnt.setVisable(false).setMask(true).setColor(tempCol);
	///eyesSad
	tempCol = { 10, 25, 10, 200 };
	tmp = v->generateFromMask("images/mask/slimeEyes3.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("eyesSad", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	tmpEnt = e.get("eyesSad");
	tmpEnt.setVisable(false).setMask(true).setColor(tempCol);
	///shine
	tempCol = { 200, 255, 200, 150 };
	tmp = v->generateFromMask("images/mask/slimeShine.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("shine", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	tmpEnt = e.get("shine");
	tmpEnt.setVisable(true).setMask(true).setColor(tempCol);	
}
void game::input()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			quit = true;
		}
	}
}
