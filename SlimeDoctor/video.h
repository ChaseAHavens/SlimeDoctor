#pragma once
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>

class video
{
public:
	video(int h, int w, std::string title);
		~video();

	SDL_Surface* theScreen;
	SDL_Window* theWindow;

private:
	int theHeight;
	int theWidth;
	std::string theTitle;
};