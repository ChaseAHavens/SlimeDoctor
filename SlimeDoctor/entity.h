#pragma once
#include <SDL.h>


class entity
{
public:
	entity();
	~entity();

	bool isVisable;
	int imageId;

	SDL_Rect tx;


	void setPos(int x, int y);
	void setSize(int h, int w);

	void setImageId(int id) { imageId = id; }
	int getImageId() { return imageId; }
	int getX() { return tx.x; }
	int getY() { return tx.y; }
	int getH() { return tx.h; }
	int getW() { return tx.w; }

	static SDL_Rect posAScaleB(SDL_Rect a, SDL_Rect b);

};