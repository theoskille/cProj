#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

typedef struct{
	SDL_Window* sdlWindow;
}Window;

Window* createWindow(int w, int h);

void destroyWindow(Window* window);

#endif
