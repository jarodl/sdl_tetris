#ifndef IO_H
#define IO_H

#include "SDL.h"
#include <iostream>

class IO
{
public:
	IO();
	void init();
	void drawRect( int x, int y, int w, int h, int color );
	void clearScreen();
	void updateScreen();

	int getScreenHeight();
	int getScreenWidth();

	int pollKey();
	int getKey();
	int isKeyDown( int key );
	
private:
	int initGraphics();
	void draw( int x, int y, int w, int h, int color );
	void clear();
	void update();

	SDL_Surface *screen;
};

#endif