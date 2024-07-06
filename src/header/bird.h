#pragma once
#include "Object.h"

class Bird: public Object {
private:
    
    int Ypos = 256;
    int animationTimer;
    
    double angle = 0;
    double accelerator1 = 0;
    double accelerator2 = 0;
    double gravity_ = 0.2;
    double jumpHeight = -5;
    double jumpTimer;
    double lastJump = 0;

    bool inJump = false;
    
    SDL_Texture* Tex1;
    SDL_Texture* Tex2;
    
public:
    int getYpos();
    bool jumpState();
    void gravity();
    void getJumpTime();
    void reset();
    void jump();
    void createTexture1(const char* path, SDL_Renderer* renderer);
    void createTexture2(const char* path, SDL_Renderer* renderer);
    // void render(SDL_Renderer* renderer);
};