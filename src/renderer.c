#include <stdlib.h>
#include "renderer.h"

Renderer* createRenderer(Window* window){
	Renderer* renderer=(Renderer*)malloc(sizeof(renderer));
	if(!renderer){
		SDL_Log("Failed to allocate memory for renderer");
		return NULL;
	}
	
	renderer->sdlRenderer=SDL_CreateRenderer(window->sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	if(!renderer->sdlRenderer){
		SDL_Log("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		free(renderer);
		return NULL;
	}
	
	SDL_SetRenderDrawColor(renderer->sdlRenderer, 0xff, 0xff, 0xff, 0xff);

	return renderer;
}

void destroyRenderer(Renderer* renderer) {
	if(renderer){
		SDL_DestroyRenderer(renderer->sdlRenderer);
		free(renderer);
	}
}
void clearRenderer(Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer->sdlRenderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(renderer->sdlRenderer);
}

void presentRenderer(Renderer* renderer) {
	SDL_RenderPresent(renderer->sdlRenderer);
}

void drawRectangle(Renderer* renderer, int x, int y, int w, int h, SDL_Color color) {
	SDL_SetRenderDrawColor(renderer->sdlRenderer, color.r, color.g, color.b, color.a);
	SDL_Rect rect={x, y, w, h};
	SDL_RenderFillRect(renderer->sdlRenderer, &rect);
}
