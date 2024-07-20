#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "background.h"
#include "button.h"
#include "object.h"
#include "gameloop.h"

class MainMenu: public Object{
private:
	
	Background menuBackground;
	Background start;
	Texture* texture;
	Button* startButton;
	bool isClicked;
	bool isSelected;
	GameLoop* gameloop;
	Mix_Chunk* startSound;

public:
	MainMenu();
	~MainMenu();
	void initSound();
	int EventHandling(SDL_Event& e);
	void Initialize(SDL_Renderer* renderer);
	void menuRender(SDL_Renderer* renderer, SDL_Event& e);
	void render(SDL_Renderer* renderer);
	bool checkSelected(int x, int y);
	void clear();
	void destroy();
	
	SDL_Rect destButton;
	void loadTexture(SDL_Renderer* renderer);
	// Button startButton(100, 100, 100, 100, Texture* texture);
};