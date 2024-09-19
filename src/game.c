#include <stdlib.h>
#include "game.h"

GameState* initGameState() {
    GameState* gameState = malloc(sizeof(GameState));
    if (!gameState) {
        SDL_Log("Failed to allocate memory for game state");
        return NULL;
    }

    //intialize ship
    gameState->ship = basic;

    //initialize player
    gameState->player.position.x = GRID_WIDTH / 2;
    gameState->player.position.y = GRID_HEIGHT / 2;
    gameState->player.color = (SDL_Color){255, 0, 0, 255};  // Red

    // Initialize grid (0 for empty, 1 for wall)
    gameState->grid = (TileType**)malloc(GRID_HEIGHT * sizeof(TileType*));
    for (int y = 0; y < GRID_HEIGHT; y++) {
        gameState->grid[y] = (TileType*)malloc(GRID_WIDTH * sizeof(TileType));
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (x == 0 || y == 0 || x == GRID_WIDTH - 1 || y == GRID_HEIGHT - 1) {
                gameState->grid[y][x] = WALL;  // Wall around the edge
            } else {
                gameState->grid[y][x] = EMPTY;  // Empty space
            }
        }
    }

    return gameState;
}

void updateGame(GameState* gameState) {
    // Add any per-frame updates here
}

void renderGame(Renderer* renderer, GameState* gameState) {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer->sdlRenderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer->sdlRenderer);

    // Draw the grid
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            SDL_Rect tileRect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
            if (gameState->grid[y][x] == 1) {
                SDL_SetRenderDrawColor(renderer->sdlRenderer, 0, 0, 0, 255);  // Black for walls
                SDL_RenderFillRect(renderer->sdlRenderer, &tileRect);
            }
            SDL_SetRenderDrawColor(renderer->sdlRenderer, 200, 200, 200, 255);  // Light grey for grid lines
            SDL_RenderDrawRect(renderer->sdlRenderer, &tileRect);
        }
    }

    // Draw the player
    SDL_Rect playerRect = {
        gameState->player.position.x * TILE_SIZE,
        gameState->player.position.y * TILE_SIZE,
        TILE_SIZE,
        TILE_SIZE
    };
    SDL_SetRenderDrawColor(renderer->sdlRenderer, 
                           gameState->player.color.r, 
                           gameState->player.color.g, 
                           gameState->player.color.b, 
                           gameState->player.color.a);
    SDL_RenderFillRect(renderer->sdlRenderer, &playerRect);

    SDL_RenderPresent(renderer->sdlRenderer);
}

void movePlayer(GameState* gameState, int dx, int dy) {
    int newX = gameState->player.position.x + dx;
    int newY = gameState->player.position.y + dy;

    // Check if the new position is within bounds and not a wall
    if (newX >= 0 && newX < GRID_WIDTH && newY >= 0 && newY < GRID_HEIGHT 
        && gameState->grid[newY][newX] == 0) {
        gameState->player.position.x = newX;
        gameState->player.position.y = newY;
    }
}

void destroyGameState(GameState* gameState) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        free(gameState->grid[y]);
    }
    free(gameState);
}
