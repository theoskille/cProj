#include <SDL2/SDL.h>
#include "window.h"
#include "renderer.h"
#include "input.h"
#include "game.h"

#define WINDOW_WIDTH (GRID_WIDTH * TILE_SIZE)
#define WINDOW_HEIGHT (GRID_HEIGHT * TILE_SIZE)

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    Window* window = createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!window) {
        SDL_Quit();
        return 1;
    }

    Renderer* renderer = createRenderer(window);
    if (!renderer) {
        destroyWindow(window);
        SDL_Quit();
        return 1;
    }

    GameState* gameState = initGameState();
    if (!gameState) {
        destroyRenderer(renderer);
        destroyWindow(window);
        SDL_Quit();
        return 1;
    }

    InputState inputState;
    initInputState(&inputState);

    while (!inputState.quit) {
        processInput(&inputState, gameState);
        updateGame(gameState);
        renderGame(renderer, gameState);
        SDL_Delay(16);  // Cap to roughly 60 FPS
    }

    destroyGameState(gameState);
    destroyRenderer(renderer);
    destroyWindow(window);
    SDL_Quit();

    return 0;
}
