#include "video.h"


int video::nextIdNumber = 0;
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
	///TODO: free all images in vector

}
int video::addImage(std::string file)
{
	int idNumber = -1;
	SDL_Surface* formattedSurface = NULL;

	SDL_Surface* loadingSurface = SDL_LoadBMP(file.c_str());
	if (loadingSurface == NULL)
	{
		std::cout << "Error Loading Image at " << file << " SDL_Error: " << SDL_GetError() << std::endl;
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
			theImages.push_back(image(formattedSurface, idNumber));
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
			try {
				SDL_BlitSurface(tmp, NULL, theScreen, NULL); //looks like cant access format at this point?
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
	for (int i = 0; i < theImages.size();i++)
	{
		if (theImages[i].idNumber == id);
		{
			returnSurf = theImages[i].theImage;
			break;
		}
	}
	return returnSurf;
}
