#include "header/sound.h"
#include <iostream>
#include <SDL2/SDL.h>

Sound::Sound()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError();
    }
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    onPlay = true;
}

bool Sound::update()
{
    return true;
}

bool Sound::init()
{   
    hitSound = Mix_LoadWAV("src2/assets/audio/hit.wav");
    if (hitSound == NULL) {
        std::cout << "Failed to load hit sound! SDL_mixer Error: %s\n", Mix_GetError();
        return false;
    }
    deadSound = Mix_LoadWAV("src2/assets/audio/die.wav");
    if (deadSound == NULL) {
        std::cout << "Failed to load hit sound! SDL_mixer Error: %s\n", Mix_GetError();
        return false;
    }
    jumpSound = Mix_LoadWAV("src2/assets/audio/wing.wav");
    if (jumpSound == NULL) {
        std::cout << "Failed to load hit sound! SDL_mixer Error: %s\n", Mix_GetError();
        return false;
    }
    scoreSound = Mix_LoadWAV("src2/assets/audio/point.wav");
    if (scoreSound == NULL) {
        std::cout << "Failed to load hit sound! SDL_mixer Error: %s\n", Mix_GetError();
        return false;
    }
    clickSound = Mix_LoadWAV("src2/assets/audio/exitSound.wav");
    if (clickSound == NULL) {
        std::cout << "Failed to load hit sound! SDL_mixer Error: %s\n", Mix_GetError();
        return false;
    }
    replaysound = Mix_LoadWAV("src2/assets/audio/replaySound.wav");
    if (replaysound == NULL) {
        std::cout << "Failed to load hit sound! SDL_mixer Error: %s\n", Mix_GetError();
        return false;
    }
    return true;
}

void Sound::playJump() {
    Mix_PlayChannel(-1, jumpSound, 0);
}

void Sound::playDead() {
    Mix_PlayChannel(-1, hitSound, 0);
    SDL_Delay(500);
    Mix_PlayChannel(-1, deadSound, 0);
}

void Sound::playScore() {
    Mix_PlayChannel(-1, scoreSound, 0);
}

void Sound::playClick() {
    Mix_PlayChannel(-1, clickSound, 0);
}

bool Sound::replaySound() {
    Mix_PlayChannel(-1, replaysound, 0);
}

void Sound::Free() {
    
}