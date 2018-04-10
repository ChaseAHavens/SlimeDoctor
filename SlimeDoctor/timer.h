#pragma once
#include <SDL.h>

class timer
{
public:
	timer();
	~timer();

	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();

	bool isStarted();
	bool isPaused();

	Uint32 startTicks;
	Uint32 pausedTicks;
	bool paused;
	bool started;
};