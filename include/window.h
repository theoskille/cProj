#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include "config.h"

typedef struct{
	SDL_Window* sdlWindow;
}Window;

Window* createWindow();

void destroyWindow(Window* window);

#endif
