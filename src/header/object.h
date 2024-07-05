# pragma once
# include "texture.h"

class Object {

private:
    SDL_Texture* texture;
    SDL_Rect src, dest;
public:
    Object();
    void setSrc(int x, int y, int w, int h);
	void setDest(int x, int y, int w, int h);
	SDL_Texture* getTexture();
	SDL_Rect& getSrc();
	SDL_Rect& getDest();
	void CreateTexture(char* address, SDL_Renderer* renderer);
};