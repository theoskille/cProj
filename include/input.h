#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "game.h"

typedef struct {
    int quit;
    int keyStates[SDL_NUM_SCANCODES];
    int mouseX;
    int mouseY;
    int mouseButtons[6];  // SDL supports up to 5 mouse buttons, plus 1 for wheel
} InputState;

void initInputState(InputState* inputState);
void processInput(InputState* inputState, GameState* gameState);
void updateKeyState(InputState* inputState, SDL_Scancode scancode, int isDown);
void updateMouseState(InputState* inputState, int button, int isDown);
void updateMousePosition(InputState* inputState, int x, int y);

#endif
