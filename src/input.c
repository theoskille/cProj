#include <string.h>
#include "input.h"

void initInputState(InputState* inputState) {
    memset(inputState, 0, sizeof(InputState));
}

void processInput(InputState* inputState, GameState* gameState) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                inputState->quit = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        movePlayer(gameState, 0, -1);
                        break;
                    case SDLK_DOWN:
                        movePlayer(gameState, 0, 1);
                        break;
                    case SDLK_LEFT:
                        movePlayer(gameState, -1, 0);
                        break;
                    case SDLK_RIGHT:
                        movePlayer(gameState, 1, 0);
                        break;
                }
                break;
        }
    }
}
