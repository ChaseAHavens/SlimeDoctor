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
	///todo: rewrite to render in order of z depth
	SDL_RenderClear(v->theRenderer);
	int entCount = e.e.size();
	int curEnt = 0;
	while (curEnt < entCount)
	{
		int imageId = e.e.at(curEnt).getImageId(); //p.second.imageId;
		if (e.e.at(curEnt).isVisable) {
			v->blit(imageId, e.e.at(curEnt).getX(), e.e.at(curEnt).getY(), e.e.at(curEnt).getH(), e.e.at(curEnt).getW());
		}
		curEnt++;
	}
	v->updateScreen();
	//*/
	/*
	for (std::pair<std::string,entity> p : e.e)
	{
		int imageId = p.second.imageId;
		v->blit(imageId, p.second.getX(), p.second.getY());

	}
	//*/


}
void game::createEntity(std::string name) //does this do anything?
{
	//if ( eList.find(name) != eList.end())
	{
		//eList[name];
	}

}
void game::maxFpsDelay()
{ //does this do anything anymore
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
	gameplay.getE(&e);

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
	e.makeEntity("shell", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 7);
	e.e.at(e.getVecPos("shell")).isMask = true;
	e.e.at(e.getVecPos("shell")).theColor = tempCol;

	//e.get("shell").isMask = true;
	//e.e["shell"].isMask = true;
	
	///inner
	tempCol = { 20, 222, 20, 60 };
	tmp = v->generateFromMask("images/mask/slimeInner.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("inner", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 8);
	e.e.at(e.getVecPos("inner")).isMask = true;
	e.e.at(e.getVecPos("inner")).theColor = tempCol;
	//*/ //e.e["inner"].isMask = true; ///todo: add better methods for accessing by name, if doesnt exist this method will create
	//e.e["inner"].theColor = tempCol;


	///eyesOpen
	tempCol = { 10, 25, 10, 200 };
	tmp = v->generateFromMask("images/mask/slimeEyes.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("eyes", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	e.e.at(e.getVecPos("eyes")).isMask = true;
	e.e.at(e.getVecPos("eyes")).theColor = tempCol;

	///eyesBlink0
	tempCol = { 10, 25, 10, 200 };
	tmp = v->generateFromMask("images/mask/slimeEyes1.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("eyes1", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	e.e.at(e.getVecPos("eyes1")).isMask = true;
	e.e.at(e.getVecPos("eyes1")).theColor = tempCol;

	///eyesOpen
	tempCol = { 10, 25, 10, 200 };
	tmp = v->generateFromMask("images/mask/slimeEyes2.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("eyes2", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	e.e.at(e.getVecPos("eyes2")).isMask = true;
	e.e.at(e.getVecPos("eyes2")).theColor = tempCol;

	///eyesOpen
	tempCol = { 10, 25, 10, 200 };
	tmp = v->generateFromMask("images/mask/slimeEyes3.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("eyesSad", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	e.e.at(e.getVecPos("eyesSad")).isMask = true;
	e.e.at(e.getVecPos("eyesSad")).theColor = tempCol;

	// */ //e.e["eyes"].isMask = true;
	//e.e["eyes"].theColor = tempCol;
	
	/*
	tmp = v->addImage("images/mask/slimeEyesOpen.png");
	tmpI = v->imageById(tmp);
	e.makeEntity("eyes", tmp, tmpI->theRect.x, tmpI->theRect.y, tmpI->theRect.h, tmpI->theRect.w, 8);
	*/
	///shine
	tempCol = { 200, 255, 200, 150 };
	tmp = v->generateFromMask("images/mask/slimeShine.png", tempCol);
	tmpI = v->imageById(tmp);
	e.makeEntity("shine", tmp, 100, 100, tmpI->theRect.h, tmpI->theRect.w, 6);
	e.e.at(e.getVecPos("shine")).isMask = true;
	e.e.at(e.getVecPos("shine")).theColor = tempCol;
	//*/ //e.e["shine"].isMask = true;
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
