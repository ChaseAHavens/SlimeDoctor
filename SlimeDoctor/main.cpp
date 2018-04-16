#include <SDL.h>
#include <stdio.h>
#include "video.h"
#include "game.h"
#include "timer.h"

int main(int argc, char* args[])
{
	game* g = new game;
	g->v = new video(1600, 900, "Slime Game");
	while (!g->quit)
	{
		g->step(g->deltaTime());
	}
	return 0;
}