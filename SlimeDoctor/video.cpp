#include "video.h"


int video::nextIdNumber = 0;
video::video(int h, int w, std::string title):
	theHeight(h), theWidth(w), theTitle(title)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
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
			theRenderer = SDL_CreateRenderer(theWindow, -1, SDL_RENDERER_ACCELERATED);
			if (theRenderer == NULL)
			{
				std::cout << "Renderer error: " << SDL_GetError() << std::endl;
			}
			else
			{
				SDL_SetRenderDrawColor(theRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL_Image loading error: " << IMG_GetError() << std::endl;
				}
				else
				{
					theScreen = SDL_GetWindowSurface(theWindow);
				}
			}
		}
	}
}
video::~video()
{
	SDL_FreeSurface(theScreen);
	theScreen = NULL;
	SDL_DestroyWindow(theWindow);
	theWindow = NULL;
	///TODO: free all images in map

}
int video::addImage(std::string file)
{
	int idNumber = -1;
	SDL_Surface* formattedSurface = NULL;

	SDL_Surface* loadingSurface = IMG_Load(file.c_str());
	if (loadingSurface == NULL)
	{
		std::cout << "Error Loading Image at " << file << " SDL_Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		formattedSurface = SDL_ConvertSurface(loadingSurface, theScreen->format, NULL);
		if (formattedSurface == NULL)
		{
			std::cout << "Error Formatting image at " << file << "SDL_Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			idNumber = nextIdNumber;
			SDL_FreeSurface(loadingSurface);
			loadingSurface = NULL;
			theImages.insert(std::pair<int, image>(idNumber, image(formattedSurface)));
			formattedSurface = NULL;
			nextIdNumber++;
		}
	}

	return idNumber;
}
void video::blit(int imageId, int x, int y)
{
	SDL_Surface* tmp = surfById(imageId);
	if (tmp == NULL) 
	{
		std::cout << "blit Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		if (theScreen == NULL)
		{
			std::cout << "screen Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			SDL_Rect tempR;
			tempR.x = x;
			tempR.y = y;
			try {
				SDL_BlitSurface(tmp, NULL, theScreen, &tempR);
			}
			catch (const char* msg)
			{
				std::cout << "exception: " << msg << std::endl;
			}
		}
	}
}
void video::updateScreen()
{
	SDL_UpdateWindowSurface(theWindow);
}
SDL_Surface* video::surfById(int id)
{
	SDL_Surface* returnSurf = NULL;
	if (theImages.find(id) != theImages.end()) { //check to see if id exists, checking with [] would create item with that key
		returnSurf = theImages[id].theImage;
	}
	/*	for (int i = 0; i < theImages.size();i++)
	{
		if (theImages[i].idNumber == id);
		{
			returnSurf = theImages[i].theImage;
			break;
		}
	}*/
	return returnSurf;
}
