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
	std::pair<Texture, SDL_Rect> exitButtonTexture;

	char* FILE_NAME = "src2/highScore.txt";

	/// Medal
	std::pair<Texture, SDL_Rect> medalTexture;

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
	void destroyScoreTextures();
	int getScore();
	std::vector<Texture> getScoreTextures(bool isBest = false);
	int getHighScore(char* FILE_NAME = "src2/highScore.txt");
	void setHighScore(int score, char* FILENAME = "src2/highScore.txt");

	// Exit Button
	std::pair<Texture, SDL_Rect>& getExitButtonTexture();

	std::pair<Texture, SDL_Rect>& getMedalTexture();

};