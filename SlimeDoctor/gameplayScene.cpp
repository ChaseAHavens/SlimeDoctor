#include "gameplayScene.h"

gameplayScene::gameplayScene() :
	e(NULL), slimeBounceAmount(10.0f)
{
	slimeBounce.start();
}
gameplayScene::~gameplayScene()
{}



bool gameplayScene::getE(entities* ent)
{
	e = ent;
	return (e != NULL);
}


void gameplayScene::setup()
{

	shell = e->get("shell");
	inner = e->get("inner");
	eyes = e->get("eyes");
	shine = e->get("shine");
	table = e->get("table");
	slimeX = shell->getX();
	slimeY = shell->getY();
	slimeH = shell->getH();
	slimeW = shell->getW();
}
void gameplayScene::step(float delta)
{
	shell->setSize(slimeH + slimeBounceH(), slimeW + slimeBounceW());
	inner->setSize(slimeH + slimeBounceH(), slimeW + slimeBounceW());
	eyes-> setSize(slimeH + slimeBounceH(), slimeW + slimeBounceW());
	shine->setSize(slimeH + slimeBounceH(), slimeW + slimeBounceW());
	//table->setSize(slimeH + slimeBounceH(), slimeW + slimeBounceW());
	//shell->setSize(slimeBounce.getTicks() % 100, slimeW);
}

float gameplayScene::slimeBounceH()
{
	return sin((float)slimeBounce.getTicks()/100.f)*slimeBounceAmount;
}

float gameplayScene::slimeBounceW()
{

	return -sin((float)slimeBounce.getTicks()/100.f)*slimeBounceAmount;
}