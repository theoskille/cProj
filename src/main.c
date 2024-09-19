#include <SDL2/SDL.h>
#include "window.h"
#include "renderer.h"
#include "game.h"
#include "input.h"


int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    Window* window = createWindow();
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
