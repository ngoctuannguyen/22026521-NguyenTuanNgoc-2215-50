#include <SDL2/SDL.h>
#include <iostream>
// #include <SDL2/SDL_ttf.h>
#include "header/gamemanager.h"

Manager::Manager() {

}

void Manager::initModules() {
    
    moduleTimer = new Timer();
    modules.push_back(moduleTimer);
    moduleWindow = new GameWindow();
    modules.push_back(moduleWindow);
    moduleInput = new Input();
    modules.push_back(moduleInput);
    moduleRenderer = new Renderer();
    modules.push_back(moduleRenderer);
    moduleObject = new Object();
    modules.push_back(moduleObject);
    moduleSound = new Sound();
    modules.push_back(moduleSound);
}

void Manager::play() {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << SDL_GetError() << std::endl;
        return;
    }

    // TTF init
    // if (TTF_Init() == -1) {
    //     std::cout << TTF_GetError() << std::endl;
    //     return;
    // }

    initModules();

    for (auto module : modules) {
        if (!(module->init())) {
            return;
        }
    }

    bool isPlaying = true;

    while (isPlaying) {

        for(auto module : modules)
			if(!(module->preUpdate()))
				isPlaying = false;

		for(auto module : modules)
			if(!(module->update()))
				isPlaying = false;

        //std::cout << isPlaying << std::endl;
    }

    for(auto module : modules)
        if(!(module->clear()))
            return;

    SDL_Quit();
}
