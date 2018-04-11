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
				SDL_SetRenderDrawColor(theRenderer, 0x00, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(theRenderer);
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
	SDL_Texture* formattedTexture = NULL;

	SDL_Surface* loadingSurface = IMG_Load(file.c_str());
	if (loadingSurface == NULL)
	{
		std::cout << "Error Loading Image at " << file << " SDL_Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		//formattedSurface = SDL_ConvertSurface(loadingSurface, theScreen->format, NULL);
		formattedTexture = SDL_CreateTextureFromSurface(theRenderer, loadingSurface);
		if (formattedTexture == NULL)
		{
			std::cout << "Error Formatting image at " << file << "SDL_Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			idNumber = nextIdNumber;
			theImages.insert(std::pair<int, image>(idNumber, image(formattedTexture, loadingSurface->h, loadingSurface->w)));
			SDL_FreeSurface(loadingSurface);
			loadingSurface = NULL;
			formattedTexture = NULL;
			nextIdNumber++;
		}
	}

	return idNumber;
}
int video::generateFromMask(std::string file, SDL_Color col)
{
	int idNumber = -1;
	SDL_Texture* formattedTexture = NULL;

	SDL_Surface* mask = IMG_Load(file.c_str());
	if (mask == NULL)
	{
		std::cout << "Error Loading Image at " << file << " SDL_Error: " << IMG_GetError() << std::endl;
	}
	SDL_Surface* loadingSurface = SDL_CreateRGBSurfaceWithFormat(0, mask->w, mask->h, mask->format->BitsPerPixel, mask->format->format);
	SDL_Rect tempR;
	tempR.h = mask->h;
	tempR.w = mask->w;
	tempR.x = 0;
	tempR.y = 0;
	SDL_FillRect(loadingSurface, &tempR, SDL_MapRGBA(mask->format, col.r, col.g, col.b, col.a));
	if (loadingSurface == NULL)
	{
		std::cout << "Error Loading Image at " << file << " SDL_Error: " << IMG_GetError() << std::endl;
	}
	SDL_BlitSurface(mask, NULL, loadingSurface, NULL);
	if (loadingSurface == NULL)
	{
		std::cout << "Error Loading Image at " << file << " SDL_Error: " << IMG_GetError() << std::endl;
	}
	SDL_SetColorKey(loadingSurface, SDL_TRUE, SDL_MapRGB(mask->format, 0xFF, 0, 0xFF));

	if (loadingSurface == NULL)
	{
		std::cout << "Error Loading Image at " << file << " SDL_Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		//formattedSurface = SDL_ConvertSurface(loadingSurface, theScreen->format, NULL);
		SDL_SetTextureBlendMode(formattedTexture, SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(formattedTexture, col.a);
		formattedTexture = SDL_CreateTextureFromSurface(theRenderer, loadingSurface);
		if (formattedTexture == NULL)
		{
			std::cout << "Error Formatting image at " << file << "SDL_Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			idNumber = nextIdNumber;
			theImages.insert(std::pair<int, image>(idNumber, image(formattedTexture, loadingSurface->h, loadingSurface->w)));
			SDL_FreeSurface(loadingSurface);
			loadingSurface = NULL;
			formattedTexture = NULL;
			nextIdNumber++;
		}
	}

	return idNumber;
}
void video::blit(int imageId, int x, int y)
{
	image* tmp = imageById(imageId);
	if (tmp == NULL)
	{
		std::cout << "blit Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		SDL_Rect tmpR = tmp->theRect;
		tmpR.x = x;
		tmpR.y = y;
		SDL_SetTextureBlendMode(tmp->theImage, SDL_BLENDMODE_BLEND);
		SDL_RenderCopy(theRenderer, tmp->theImage, NULL, &tmpR);
	}
	
}
void video::updateScreen()
{
	SDL_RenderPresent(theRenderer);
	//SDL_RenderClear(theRenderer);
	//SDL_UpdateWindowSurface(theWindow);
}
image* video::imageById(int id)
{
	image* returnImage = NULL;
	if (theImages.find(id) != theImages.end()) { //check to see if id exists, checking with [] would create item with that key
		returnImage = &theImages[id];
	}
	/*	for (int i = 0; i < theImages.size();i++)
	{
		if (theImages[i].idNumber == id);
		{
			returnSurf = theImages[i].theImage;
			break;
		}
	}*/
	return returnImage;
}
