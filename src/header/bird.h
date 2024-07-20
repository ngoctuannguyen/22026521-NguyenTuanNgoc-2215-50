#pragma once
#include "object.h"

class Bird: public Object {
private:
    
    int x, yPos = 10;
    int animationTimer;
    
    double angle = 0;
    double accelerator1 = 0;
    double accelerator2 = 0;
    double gravity = 5;
    double jumpHeight = -5;
    double jumpTimer;
    double lastJump = 0;
    double velocity;

    bool inJump = false;
    
    SDL_Texture* Tex1;
    SDL_Texture* birdTexture;
    
    int BIRD_WIDTH;
    const int BIRD_HEIGHT = 100;
    const double FLAP_STRENGTH = -15.00f;

    SDL_Renderer* renderer;

    
public:
    // Bird(SDL_Texture* birdTexture);
    int getYpos();
    bool jumpState();
    SDL_Renderer* getRender();
    void getJumpTime();
    void reset();
    void jump();
    SDL_Texture* getTexture();
    void render(SDL_Renderer* renderer, SDL_Texture* texture);
    void update();
    void flap();
    void setTexture(SDL_Texture* texture);
    void setRender(SDL_Renderer* renderer_);
    SDL_Rect getRect();
};