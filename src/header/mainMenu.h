#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "background.h"
#include "button.h"

class MainMenu: public Object{
private:
	
	// Mix_Chunk* startSound;	
	Background menuBackground;
	Background start;
	Texture* texture;
	Button startButton;

public:
	MainMenu();
	~MainMenu();
	
	int EventHandling(SDL_Event& e);
	void Initialize(SDL_Renderer* renderer);
	void menuRender(SDL_Renderer* renderer, SDL_Event& e);
	void render(SDL_Renderer* renderer);
	bool checkSelected(int x, int y);
	void clear();
	
	SDL_Rect destButton;
	// Button startButton(100, 100, 100, 100, Texture* texture);
};