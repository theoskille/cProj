#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "window.h"


typedef struct{
	SDL_Renderer* sdlRenderer;
}Renderer;

Renderer* createRenderer(Window* window);

void destroyRenderer(Renderer* renderer);

void clearRenderer(Renderer* renderer);

void presentRenderer(Renderer* renderer);

void drawRectangle(Renderer* renderer, int x, int y, int w, int h, SDL_Color color);

#endif
