#pragma once
#include "module.h"
#include "texture.h"
#include <SDL2/SDL_mixer.h>

class Sound : public Module {
private:
    Mix_Chunk* jumpSound;
    Mix_Chunk* deadSound;
    Mix_Chunk* hitSound;
    Mix_Chunk* scoreSound;
    Mix_Chunk* clickSound;
    Mix_Chunk* replaysound;

    bool onPlay;
public:
    Sound();
    bool init() override;
    bool update() override;
    void playJump();
    void playDead();
    void playScore();
    void playClick();
    bool getOnPlay();
    void setOnPlay(bool onPlay);
    bool replaySound();
    void Free();
};