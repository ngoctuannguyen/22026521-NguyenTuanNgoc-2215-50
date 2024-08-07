#pragma once
#include <vector>
#include "texture.h"

struct Pipe {
    SDL_Rect rect;
    bool isBottom;
};

class Pipes {
private:
    std::vector<Pipe> pipes;
    Texture texture;
public:
    Pipes();
    Pipes(const Texture& texture, const std::vector<Pipe>& pipes);
    void resetHeight(std::vector<Pipe>& pipes);
    std::vector<Pipe>& getPipes();
    Texture& getTexture();
};
