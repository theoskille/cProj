#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "renderer.h"

#define TILE_SIZE 32
#define GRID_WIDTH 25
#define GRID_HEIGHT 19

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    SDL_Color color;
} Player;

typedef struct {
    Player player;
    int grid[GRID_HEIGHT][GRID_WIDTH];
    // Add more game state variables as needed
} GameState;

GameState* initGameState();
void updateGame(GameState* gameState);
void renderGame(Renderer* renderer, GameState* gameState);
void movePlayer(GameState* gameState, int dx, int dy);
void destroyGameState(GameState* gameState);

#endif
