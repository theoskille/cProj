#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "renderer.h"
#include "config.h"

//enum for tile types
typedef enum {
    EMPTY,
    WALL,
    DOOR
} TileType;

typedef enum{
    basic
}ShipType;

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
    TileType** grid;
    ShipType ship;
} GameState;

GameState* initGameState();
void updateGame(GameState* gameState);
void renderGame(Renderer* renderer, GameState* gameState);
void movePlayer(GameState* gameState, int dx, int dy);
void destroyGameState(GameState* gameState);

#endif
