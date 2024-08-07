#include "header/gamestatemanager.h"

void GameStateManager::setGameState(int state)
{
    gameState = state;
}

int GameStateManager::getGameState() {
    return gameState;
}