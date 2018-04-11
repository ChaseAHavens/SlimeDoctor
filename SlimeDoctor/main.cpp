#include <SDL.h>
#include <stdio.h>
#include "video.h"
#include "game.h"
#include "timer.h"

int main(int argc, char* args[])
{
	game* g = new game;
	g->v = new video(1600, 900, "Slime Game");
	while (1)
	{
		g->step(g->deltaTime());
		g->updateScreen();

	}
	
	/*video* v = new video(1600, 900, "Slime Game");
	int iId1 = v->addImage("preview.bmp");
	int iId2 = v->addImage("preview2.bmp");
	int iId3 = v->addImage("preview3.bmp");

	int tableId = v->addImage("images/table.png");

	int slimeOuterShell = v->addImage("images/masks/slimeOuterShell.png");
	int slimeInnerFill = v->addImage("images/masks/slimeInnerFill.png");

	int slimeEyesOpenId = v->addImage("images/masks/slimeEyesOpen.png");
	int slimeEyesBlink0Id = v->addImage("images/masks/slimeEyesBlink0.png");
	int slimeEyesBlink1Id = v->addImage("images/masks/slimeEyesBlink1.png");
	int slimeEyesSad = v->addImage("images/masks/slimeEyesSad.png");
	int slimeShine = v->addImage("images/masks/slimeShine.png");

	v->blit(tableId, 1, 1);
	v->updateScreen();
	SDL_Delay(1000);


	v->blit(slimeOuterShell, 100, 100);
	v->updateScreen();
	SDL_Delay(1000);

	v->blit(slimeEyesOpenId, 100, 100);
	v->updateScreen();
	SDL_Delay(1000);
	*/
	std::cout << "Reached end of program, type something and press enter to close" << std::endl;
	char pause;
	std::cin >> pause;

	return 0;
}