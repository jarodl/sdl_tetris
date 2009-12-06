#ifndef IO_H
#define IO_H

#include <iostream>
#include <SDL/SDL.h>

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
	
private:
	int initGraphics();
	void draw( int x, int y, int w, int h, int color );
	void clear();
	void update();

	SDL_Surface *screen;
};

#endif
