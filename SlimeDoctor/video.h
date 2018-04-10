#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "image.h"
#include <vector>
#include <map>



class video
{
public:
	video(int h, int w, std::string title);
		~video();

	SDL_Surface* theScreen;
	SDL_Renderer* theRenderer;
	SDL_Window* theWindow;

	int addImage(std::string file);
	image* imageById(int id);

	void blit(int imageId, int x, int y);

	std::map <int, image> theImages;
	void updateScreen();

	static int nextIdNumber;
private:
	int theHeight;
	int theWidth;
	std::string theTitle;



	
};