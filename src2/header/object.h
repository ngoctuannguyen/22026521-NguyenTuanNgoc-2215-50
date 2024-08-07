#pragma once
#include "module.h"
#include "bird.h"
#include "scroll.h"
#include "common.h"
#include "gamestatemanager.h"
// #include <SDL2/SDL_ttf.h>

class Object : public Module
{
private:
	Bird bird;
	Scrolling scrollingBackground;
	Texture menuTexture;
	Texture deadTexture;
	Texture soundTexture;
	GameStateManager gSManager;
	// TTF_Font* font;
	SDL_Texture* scoreTexture;
	int score;
	float xMoved;
	bool onPlay;
	bool reachFirstPipe = false;
public:
	Object();
	bool update() override;
	Bird& getBird();
	Bird& Bird();
	Scrolling& getScrollingBackground();
	GameStateManager& getGameStateManager();
	GameStateManager& gameStateManager();
	Texture& getMenuTexture();
	Texture& getSoundTexture();
	SDL_Rect getSoundRect();
	Texture& getDeadTexture();
	SDL_Texture* ScoreTexture();
	bool getOnPlay();
	void setOnPlay(bool onPlay);
	void toggleSound();
	void resetGame();
};