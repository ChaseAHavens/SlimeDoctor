#pragma once
#include <SDL.h>
#include <string>

class entity
{
public:
	entity();
	~entity();



	bool isVisable;
	int imageId;

	bool isMask;
	SDL_Color theColor;

	SDL_Rect tx;

	
	void setPos(int x, int y);
	void setSize(int h, int w);
	void setZ(int z) { theZ = z;}

	void setImageId(int id) { imageId = id; }
	int getImageId() { return imageId; }
	int getZ() { return theZ;}
	int getX() { return tx.x; }
	int getY() { return tx.y; }
	int getH() { return tx.h; }
	int getW() { return tx.w; }

	static SDL_Rect posAScaleB(SDL_Rect a, SDL_Rect b);

private:
	int theZ; //lower = closer to surface



};