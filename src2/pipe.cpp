#include "header/pipe.h"
#include <iostream>

int genRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

Pipes::Pipes() {
    
}

Pipes::Pipes(const Texture &texture, const std::vector<Pipe> &pipes) :
    texture(texture), pipes(pipes)
{}

void Pipes::resetHeight(std::vector<Pipe> &pipes)
{
    for (int i = 0; i < pipes.size(); i += 2) { // Pipes size: 4
        int randomNumber = genRandomNumber(100, 300);
        pipes[i].rect.h = randomNumber;
        std::cout << "Random number: " << randomNumber << std::endl;
        pipes[i + 1].rect.h = 640 - randomNumber - 150; 
        pipes[i + 1].rect.y = 640 - 50 - pipes[i + 1].rect.h;
    }
}

std::vector<Pipe>& Pipes::getPipes()
{
    return pipes;
}

Texture& Pipes::getTexture()
{
    return texture;
}
