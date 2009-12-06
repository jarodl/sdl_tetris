#include "IO.h"

// public
IO::IO()
{
	init();
}

void IO::init()
{
	if ( initGraphics() != 0 )
		std::cerr << "Could not initialize graphics." << std::endl;
}

void IO::drawRect( int x, int y, int w, int h, int color )
{
	draw( x, y, w, h, color );
}

void IO::clearScreen()
{
	clear();
}

void IO::updateScreen()
{
	update();
}

int IO::getScreenHeight()
{
	return screen->h;
}

int IO::getScreenWidth()
{
	return screen->w;
}

int IO::pollKey()
{
	SDL_Event event;
	while ( SDL_PollEvent(&event) ) 
	{
		switch (event.type) {
			case SDL_KEYDOWN:
				return event.key.keysym.sym;
			case SDL_QUIT:
				exit(3);
		}
	}
	return -1;
}

int IO::getKey()
{
	SDL_Event event;
	while (true)
	{
	  SDL_WaitEvent(&event);
	  if (event.type == SDL_KEYDOWN)
		  break;
      if (event.type == SDL_QUIT)
		  exit(3);
	};
	return event.key.keysym.sym;
}

int IO::isKeyDown( int key )
{
	Uint8* mKeytable;
	int mNumkeys;

	SDL_PumpEvents();
	mKeytable = SDL_GetKeyState(&mNumkeys);

	return mKeytable[key];
}

// private
int IO::initGraphics()
{
	const SDL_VideoInfo *info;
	Uint8  video_bpp;
	Uint32 videoflags;
        
	// Initialize SLDbb
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",SDL_GetError());
		return 1;
	}
	atexit(SDL_Quit);

	info = SDL_GetVideoInfo();
	if ( info->vfmt->BitsPerPixel > 8 ) {
		video_bpp = info->vfmt->BitsPerPixel;
	} else {
		video_bpp = 16;
	}
	videoflags = SDL_SWSURFACE | SDL_DOUBLEBUF;

	if (( screen = SDL_SetVideoMode(640,480,video_bpp,videoflags)) == NULL ) {
		fprintf(stderr, "Couldn't set %ix%i video mode: %s\n", 640, 480, SDL_GetError());
		return 2;
	}
	return 0;
}

void IO::draw( int x, int y, int w, int h, int color )
{
	SDL_Rect rect = { x, y, w, h };
	SDL_FillRect(screen, &rect, color);
}

void IO::clear()
{
	SDL_FillRect(screen, NULL, 0x00000000);
}

void IO::update()
{
	SDL_Flip(screen);
}
