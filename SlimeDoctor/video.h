#pragma once
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "image.h"
#include <vector>


class video
{
public:
	video(int h, int w, std::string title);
		~video();

	SDL_Surface* theScreen;
	SDL_Window* theWindow;

	int addImage(std::string file);
	SDL_Surface* surfById(int id);

	void blit(int imageId, int x, int y);

	std::vector <image> theImages;
	void updateScreen();

	static int nextIdNumber;
private:
	int theHeight;
	int theWidth;
	std::string theTitle;



	
};