# pragma once
# include "texture.h"

class Object {

private:
    SDL_Texture* texture;
protected:
    SDL_Rect src, dest;
	bool is_click;
	bool is_select;
public:
    Object();
    void setSrc(int x, int y, int w, int h);
	void setDest(int x, int y, int w, int h);
	SDL_Texture* getTexture();
	SDL_Rect& getSrc();
	SDL_Rect& getDest();
	void createTexture(const char* address, SDL_Renderer* renderer);
	bool isClicked(bool is_click);
	bool isSelected(bool is_select);
	void render(SDL_Renderer* renderer);
	void loadTexture(SDL_Renderer* renderer);
};