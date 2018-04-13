#pragma once
#include <SDL.h>
#include <string>

class entity
{
public:
	entity(std::string name);
	entity(std::string name, int id, int x, int y, int h, int w, int z);
	entity() {};
	~entity();





	
	entity& setPos(int x, int y);
	entity& setSize(int h, int w);
	entity& setZ(int z);
	entity& setVisable(bool vis);
	entity& setImageId(int id);
	entity& setMask(bool mask);
	entity& setColor(SDL_Color col);
	
	int getImageId() { return imageId; }
	int getZ() { return theZ;}
	int getX() { return tx.x; }
	int getY() { return tx.y; }
	int getH() { return tx.h; }
	int getW() { return tx.w; }
	bool getVis() { return isVisable; }
	bool getMask() { return isMask; }
	std::string getName() {	return theName;}
	static SDL_Rect posAScaleB(SDL_Rect a, SDL_Rect b);

private:
	int theZ; //lower = closer to surface
	std::string theName;
	bool isVisable;
	int imageId;

	bool isMask;
	SDL_Color theColor;

	SDL_Rect tx;

};