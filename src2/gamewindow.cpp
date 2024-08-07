#include "header/gamewindow.h"

GameWindow::GameWindow()
{
    gameWindow = SDL_CreateWindow("Flappy Bird", 
                        SDL_WINDOWPOS_UNDEFINED, 
                        SDL_WINDOWPOS_UNDEFINED, 
                        WINDOW_WIDTH,
                        WINDOW_HEIGHT,
                        0);
}


SDL_Window* GameWindow::getWindow()
{
    return gameWindow;
}

bool GameWindow::update()
{
    return true;
}

bool GameWindow::clear()
{   
    SDL_DestroyWindow(gameWindow);
    return true;
}
