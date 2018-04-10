#include "video.h"

video::video(int h, int w, std::string title):
	theHeight(h), theWidth(w), theTitle(title)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Video Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		theWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, theHeight, theWidth, SDL_WINDOW_SHOWN);
		if (theWindow == NULL)
		{
			std::cout << "Window creation error: " << SDL_GetError() << std::endl;
		}
		else
		{
			theScreen = SDL_GetWindowSurface(theWindow);
		}
	}
}
video::~video()
{
	SDL_FreeSurface(theScreen);
	theScreen = NULL;
	SDL_DestroyWindow(theWindow);
	theWindow = NULL;
}