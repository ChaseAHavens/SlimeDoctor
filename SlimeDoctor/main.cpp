#include <SDL.h>
#include <stdio.h>
#include "video.h"

int main(int argc, char* args[])
{
	video* v = new video(640, 480, "Slime Game");
	int iId = v->addImage("preview.bmp");
	v->blit(iId, 1, 1);
	v->updateScreen();
	char pause;
	std::cin >> pause;

	return 0;
}