#include "gameplayScene.h"

gameplayScene::gameplayScene() :
	e(NULL), slimeBounceAmount(10.0f), slimeBlinkDelay(2000)
{
	eS = OPEN;
	slimeTime.start();
}
gameplayScene::~gameplayScene()
{
}
bool gameplayScene::getE(entities* ent)
{
	e = ent;
	return (e != NULL);
}
void gameplayScene::setup()
{
	setupSlime();
}
void gameplayScene::step(float delta)
{
	animateBounce();
	animateBlink();
}
float gameplayScene::slimeBounceH()
{
	return sin((float)slimeTime.getTicks()/100.f)*slimeBounceAmount;
}
float gameplayScene::slimeBounceW()
{
	return -sin((float)slimeTime.getTicks()/100.f)*slimeBounceAmount;
}
void gameplayScene::setupSlime()
{	
	shell =		&e->get("shell");
	inner =		&e->get("inner");
	eyes =		&e->get("eyes");
	eyes1 =		&e->get("eyes1");
	eyes2 =		&e->get("eyes2");
	eyesSad =	&e->get("eyesSad");
	shine =		&e->get("shine");
	table =		&e->get("table");

	slimeX = (float)shell->getX();
	slimeY = (float)shell->getY();
	slimeH = (float)shell->getH();
	slimeW = (float)shell->getW();
}
void gameplayScene::animateBounce()
{
	float squishH = slimeH + slimeBounceH();
	float squishW = slimeW + slimeBounceW();
	float offsetX = slimeX + slimeBounceH() / 2.f;
	float offsetY = slimeY + slimeBounceW() / 2.f;
	inner->		setSize(squishH, squishW);
	eyes->		setSize(squishH, squishW);
	eyes1->		setSize(squishH, squishW);
	eyes2->		setSize(squishH, squishW);
	eyesSad->	setSize(squishH, squishW);
	shine->		setSize(squishH, squishW);
	shell->		setSize(squishH, squishW);
	
	shell->		setPos(offsetX, offsetY);
	inner->		setPos(offsetX, offsetY);
	eyes->		setPos(offsetX, offsetY);
	eyes1->		setPos(offsetX, offsetY);
	eyes2->		setPos(offsetX, offsetY);
	eyesSad->	setPos(offsetX, offsetY);
	shine->		setPos(offsetX, offsetY);
}
void gameplayScene::animateBlink()
{
	int time = slimeTime.getTicks() % slimeBlinkDelay;
	int startBlink = slimeBlinkDelay - (slimeBlinkDelay * 0.08);
	int endBlink = slimeBlinkDelay - (slimeBlinkDelay * 0.05);
	switch (eS)
	{
	case OPEN:
		if (time > startBlink)
		{
			eS = BLINK1;
			slimeChangeEyes();
		}
		break;
	case BLINK1:
		if (time > endBlink)
		{
			eS = BLINK2;
			slimeChangeEyes();
		}
		break;
	case BLINK2:
		if (time < startBlink)
		{
			eS = OPEN;
			slimeChangeEyes();
		}
		break;
	}
}
void gameplayScene::slimeChangeEyes()
{
	switch (eS)
	{
	case OPEN:
		eyes->		setVisable(true);
		eyes1->		setVisable(false);
		eyes2->		setVisable(false);
		eyesSad->	setVisable(false);
		break;
	case BLINK1:
		eyes->		setVisable(false);
		eyes1->		setVisable(true);
		eyes2->		setVisable(false);
		eyesSad->	setVisable(false);
		break;
	case BLINK2:
		eyes->		setVisable(false);
		eyes1->		setVisable(false);
		eyes2->		setVisable(true);
		eyesSad->	setVisable(false);
		break;
	case SAD:
		eyes->		setVisable(false);
		eyes1->		setVisable(false);
		eyes2->		setVisable(false);
		eyesSad->	setVisable(true);
		break;
	}
}