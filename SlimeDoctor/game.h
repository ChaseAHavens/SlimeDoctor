#pragma once
#include <SDL.h>
#include "video.h"
#include "entity.h"
#include "image.h"

class game
{
public:
	game();
	~game();

	void step();
	void updateScreen();


	video* v;

	

}