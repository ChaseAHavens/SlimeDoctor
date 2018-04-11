#include "game.h"

game::game() :
	fps(60), tpf(1000.0f/60), g(STARTUP), quit(false)
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
		SDL_Delay(2000);
		g = GAME_LOAD_SCENE_1;
		break;
	case GAME_LOAD_SCENE_1:
		e.clearAllEntities();
		makeGAMEEntities();
		g = GAME_SCENE_1;
		break;
	case GAME_SCENE_1:
		updateScreen();
		input();
		break;
	case QUIT:

		break;
	}
}
void game::updateScreen()
{
	///todo: rewrite to render in order of z depth
	SDL_RenderClear(v->theRenderer);


	/*SDL_RenderClear(v->theRenderer);
	int entityCount = e.e.count;
	int currentEntity = 
	//*/
	/*
	for (std::pair<std::string,entity> p : e.e)
	{
		int imageId = p.second.imageId;
		v->blit(imageId, p.second.getX(), p.second.getY());

	}
	//*/
	v->updateScreen();

}
void game::createEntity(std::string name) 
{
	//if ( eList.find(name) != eList.end())
	{
		//eList[name];
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
	e.makeEntity("splashPage", tmp, tmpI->theRect.x, tmpI->theRect.y, tmpI->theRect.h, tmpI->theRect.w, 10);
}
void game::makeGAMEEntities()
{
	int tmp;
	image* tmpI;
	SDL_Color tempCol;

	//table
	tmp = v->addImage("images/table.png");
	tmpI = v->imageById(tmp);
	e.makeEntity("table", tmp, tmpI->theRect.x, tmpI->theRect.y, tmpI->theRect.h, tmpI->theRect.w, 9);
	//tmp = v->addImage("images/masks/slimeOuterShell.png");

	//shell 
	tempCol = { 10, 222, 10, 199 };
	tmp = v->generateFromMask("images/mask/slimeShell.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("shell", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 8);
	e.e.at(e.getVecPos("shell")).isMask = true;
	e.e.at(e.getVecPos("shell")).theColor = tempCol;

	//e.get("shell").isMask = true;
	//e.e["shell"].isMask = true;
	
	//inner
	tempCol = { 20, 222, 20, 60 };
	tmp = v->generateFromMask("images/mask/slimeInner.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("inner", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 8);
	e.e.at(e.getVecPos("inner")).isMask = true;
	e.e.at(e.getVecPos("inner")).theColor = tempCol;
	//e.e["inner"].isMask = true; ///todo: add better methods for accessing by name, if doesnt exist this method will create
	//e.e["inner"].theColor = tempCol;


	//eyesOpen
	tempCol = { 255, 255, 255, 200 };
	tmp = v->generateFromMask("images/masks/slimeEyesOpen.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("eyes", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 8);
	e.e.at(e.getVecPos("eyes")).isMask = true;
	e.e.at(e.getVecPos("eyes")).theColor = tempCol;

	//e.e["eyes"].isMask = true;
	//e.e["eyes"].theColor = tempCol;
	
	/*
	tmp = v->addImage("images/masks/slimeEyesOpen.png");
	tmpI = v->imageById(tmp);
	e.makeEntity("eyes", tmp, tmpI->theRect.x, tmpI->theRect.y, tmpI->theRect.h, tmpI->theRect.w, 8);
	*/
	//shine
	tempCol = { 0, 0, 0, 150 };
	tmp = v->generateFromMask("images/masks/slimeShine.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("shine", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 8);
	e.e.at(e.getVecPos("shine")).isMask = true;
	e.e.at(e.getVecPos("shine")).theColor = tempCol;
	//e.e["shine"].isMask = true;
	//e.e["shine"].theColor = tempCol;
	/*
	tmp = v->addImage("images/masks/slimeShine.png");
	tmpI = v->imageById(tmp);
	e.makeEntity("shine", tmp, tmpI->theRect.x, tmpI->theRect.y, tmpI->theRect.h, tmpI->theRect.w, 8);
//*/
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
