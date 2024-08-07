#pragma once
#include "module.h"
#include "bird.h"
#include "scroll.h"
#include "common.h"
#include "gamestatemanager.h"
#include <fstream>

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
	int bestScore = 0;
	float xMoved;
	bool onPlay;
	bool reachFirstPipe = false;

	//Score Texture
	std::vector<Texture> scoreTextures = {};

	// Tutorial 
	Texture tutorialTexture;
	Texture tutorialButtonTexture;
	bool tutorialState = false;

	// // Exit button
	// Texture exitButtonTexture;
	// bool exitButtonState = 

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

	// Tutorial
	Texture& getTutorialTexture();
	Texture& getTutorialButtonTexture();
	bool getTutorialState();
	void setTutorialState(bool tutorialState);

	// Score Render
	void initScoreTextures();
	int getScore();
	std::vector<Texture> getScoreTextures();
	int getHighScore(char* FILE_NAME = "src2/highScore.txt");
	void setHighScore(int score, char* FILENAME = "src2/highScore.txt");
};