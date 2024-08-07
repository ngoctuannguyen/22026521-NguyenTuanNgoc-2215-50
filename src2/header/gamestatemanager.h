#pragma once

enum GameState {
    MENU = 0,
    PLAY,
    DEAD
};

class GameStateManager {
private:
    int gameState = MENU;
public:
    GameStateManager() = default;
    void setGameState(int state);
    int getGameState();

};