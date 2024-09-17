#include "window.h"
#include <stdlib.h>

Window* createWindow(int w, int h){
	Window* window=(Window*)malloc(sizeof(Window));
	if(!window){
		SDL_Log("Failed to allocate memory for window");
		return NULL;
	}

	window->sdlWindow=SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	if(!window->sdlWindow){
		SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		free(window);
		return NULL;
	}
	return window;
}

void destroyWindow(Window* window){
	if(window){
		SDL_DestroyWindow(window->sdlWindow);
		free(window);
	}
}

