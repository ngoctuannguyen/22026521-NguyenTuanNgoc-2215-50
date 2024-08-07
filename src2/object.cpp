#include <algorithm>
#include "header/object.h"
#include "header/gamemanager.h"
#include "header/render.h"
#include "header/timer.h"
#include "header/sound.h"
#include <iostream>
#include <vector>
#include <string.h>

bool detectCollision(Bird& bird, std::pair<Background,float>& backgrounds);
bool detectCollision(Bird& bird, Scrolling& scrollingBackgrounds);
bool checkGroundCollision(Bird& bird);

std::map<BirdDirection, Texture> createBirdDirectionTextures()
{	
	SDL_Renderer* renderer = gameManager->moduleRenderer->getRenderer();
	Texture birdTextureM("src2/assets/textures/birdM.png", renderer);
	Texture birdTextureU("src2/assets/textures/birdU.png", renderer);
	Texture birdTextureD("src2/assets/textures/birdD.png", renderer);
	return {
		{ 
			MID, birdTextureM
		},
		{ 
			UP, birdTextureU
		},
		{ 
			DOWN, birdTextureD
		}
	};
}

Bird createBird()
{	
	SDL_Rect birdRect = {80, 400, 30, 30};
	return Bird(birdRect, createBirdDirectionTextures());
}

Pipes createPipes(bool firstScrolling = true)
{	
	SDL_Renderer* renderer = gameManager->moduleRenderer->getRenderer();
	Texture texture("src2/assets/textures/pipe.png", renderer);
	std::vector<Pipe> pipes(8);

	Pipes pipesObj(texture, pipes);

	for (int i = 0, x = 0; i < pipes.size(); i += 2, x += 200) {
		pipes[i] = {(SDL_Rect) {x, 0, 50, 200}, true};
		pipes[i + 1] = {(SDL_Rect) {x, 390, 50, 200}, false};
	}

	pipesObj.resetHeight(pipes);

	if (firstScrolling) {
		for (int i = 0, x = 0; i < pipes.size(); i += 2, x += 200) {
			if (i == 0 || i == 2) {
				pipes[i] = {(SDL_Rect) {x, 0, 50, 0}, true};
				pipes[i + 1] = {(SDL_Rect) {x, 390, 50, 0}, false};
			}
			std::cout << pipes[i].rect.h << " " << pipes[i + 1].rect.h << std::endl;
		}
	}

	return Pipes(texture, pipes);
}

Scrolling createScrollingBackground()
{
	const Pipes pipesFirstScroll = createPipes();
	const Pipes pipesAfterFirstScroll = createPipes(false);
	SDL_Renderer* renderer = gameManager->moduleRenderer->getRenderer();
	Texture baseTexture("src2/assets/textures/base.png", renderer);
	Texture backgroundTexture("src2/assets/textures/background.png", renderer);
	Background backgroundsFirstScroll({{backgroundTexture, {0, 0, 800, 640}},
			{baseTexture, {0, 590, 800, 50}}}, pipesFirstScroll);
	Background backgroundsAfterFirstScroll({{backgroundTexture, {0, 0, 800, 640}},
			{baseTexture, {0, 590, 800, 50}}}, pipesAfterFirstScroll);

	return Scrolling({{backgroundsFirstScroll, 0}, {backgroundsAfterFirstScroll, 800}});
}

int Object::getHighScore(char* FILE_NAME) {
    std::ifstream file(FILE_NAME);
    int highScore = 0;
    if (file.is_open()) {
        file >> highScore;
        if (file.fail()) {
            highScore = 0; 
			// Handle case where the file might be empty or not contain an integer
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading: " << FILE_NAME << std::endl;
    }
    return highScore;
}

void Object::setHighScore(int highScore, char* FILENAME) {
    int currentHighScore = getHighScore(FILENAME);

    if (highScore > currentHighScore) {
        std::ofstream file(FILENAME);
        if (file.is_open()) {
            file << highScore;
            file.close();
        } else {
            std::cerr << "Unable to open file for writing: " << FILENAME << std::endl;
        }
    }
}


Object::Object() :

	bird(createBird()),
	scrollingBackground(createScrollingBackground()),
	menuTexture(Texture("src2/assets/textures/menu.png", gameManager->moduleRenderer->getRenderer())),
	deadTexture(Texture("src2/assets/textures/gameover.png", gameManager->moduleRenderer->getRenderer())),
	score(0),
	xMoved(0),
	soundTexture(Texture("src2/assets/textures/sound.png", gameManager->moduleRenderer->getRenderer())),
	onPlay(true),
	tutorialTexture(Texture("src2/assets/textures/tutorial.png", gameManager->moduleRenderer->getRenderer())),
	tutorialButtonTexture(Texture("src2/assets/textures/tutorialButton.png", gameManager->moduleRenderer->getRenderer())),
	exitButtonTexture(Texture("src2/assets/textures/quit.png", gameManager->moduleRenderer->getRenderer()), (SDL_Rect) {750, 0, 50, 50})
{
	initScoreTextures();
}

std::pair<Texture, SDL_Rect>& Object::getExitButtonTexture() {
	return exitButtonTexture;
}

bool Object::getOnPlay() {
	return onPlay;
}

void Object::setOnPlay(bool onPlay_) {
	onPlay = onPlay_;
}

SDL_Rect Object::getSoundRect() {
	// int w, h;
	// SDL_QueryTexture(soundTexture.getTexture(), NULL, NULL, &w, &h);
	SDL_Rect rect = {750, 0, 50, 50};
	return rect;
}

void Object::toggleSound() {
	std::cout << "Toggle sound: " << onPlay << std::endl;
	if (!onPlay) {
		Mix_Pause(-1);
	}
	else {
		Mix_Resume(-1);
	}
}

int Object::getScore() {
	return score;
}

void Object::destroyScoreTextures() {
	for (int i = 0; i < scoreTextures.size(); i++) {
		SDL_DestroyTexture(scoreTextures[i].getTexture());
	}
}

 void Object::initScoreTextures() {
	SDL_Renderer* renderer = gameManager->moduleRenderer->getRenderer();
	scoreTextures.push_back(Texture("src2/assets/textures/large/0.png", renderer));
	scoreTextures.push_back(Texture("src2/assets/textures/large/1.png", renderer));	
	scoreTextures.push_back(Texture("src2/assets/textures/large/2.png", renderer));
	scoreTextures.push_back(Texture("src2/assets/textures/large/3.png", renderer));
	scoreTextures.push_back(Texture("src2/assets/textures/large/4.png", renderer));
	scoreTextures.push_back(Texture("src2/assets/textures/large/5.png", renderer));
	scoreTextures.push_back(Texture("src2/assets/textures/large/6.png", renderer));
	scoreTextures.push_back(Texture("src2/assets/textures/large/7.png", renderer));
	scoreTextures.push_back(Texture("src2/assets/textures/large/8.png", renderer));
	scoreTextures.push_back(Texture("src2/assets/textures/large/9.png", renderer));
}


std::vector<Texture> Object::getScoreTextures(bool isBest) {

	std::string score = std::to_string(isBest ? getHighScore(FILE_NAME) : getScore());
	std::vector<Texture> scoreTextureForRender = {};
	for (int i = 0; i < score.size(); i++) {
		scoreTextureForRender.push_back(scoreTextures[score[i] - '0']);
	}
	return scoreTextureForRender;
}



bool Object::update()
{
	if(gSManager.getGameState() != PLAY)
		return true;

	float deltaTime = gameManager->moduleTimer->getDeltaTime();

    bird.updateYPos(deltaTime); 

	float xMove = deltaTime * 0.5f;
	// float xMove = 0.2f;
	xMoved += xMove;

	// std::cout << xMoved << std::endl;
	
	// for (auto& background : scrollingBackground.getBackgrounds()) {
	// 	for (auto& pipe : background.first.getPipes().getPipes()) {
	// 		if (!pipe.isPassed() && bird.getRect().x >= pipe.rect.x + pipe.rect.w) {
	// 			score++;
	// 			pipe.setPassed(true);
	// 			if (onPlay) {
	// 				gameManager->moduleSound->playScore();
	// 			}
	// 			xMoved = 0.0f;
	// 		}
	// 	}
	// }

    if(!reachFirstPipe)
	{
		if(xMoved >= 400.0f)
		{
			reachFirstPipe = true;
			score++;
			if (onPlay)
				gameManager->moduleSound->playScore();
			xMoved = 0.0f;
		}
	}
	else {
		if(xMoved >= 200.0f)
		{
			score++;
			if (onPlay)
				gameManager->moduleSound->playScore();
			xMoved = 0.0f;
		}
	}

	///std::cout << scrollingBackground.getBackgrounds().size() << std::endl;

	scrollingBackground.move(xMove, -800.0f, 800.0f);

	if(detectCollision(bird, scrollingBackground)) {
		std::cout << "Collision!" << std::endl;
		gSManager.setGameState(DEAD);
		setHighScore(getScore());
	}

	return true;
}

Texture& Object::getSoundTexture() {
	return soundTexture;
}

Bird& Object::getBird()
{
	return bird;
}

Bird& Object::Bird()
{
	return bird;
}

Scrolling& Object::getScrollingBackground()
{
	return scrollingBackground;
}


GameStateManager& Object::getGameStateManager()
{
	return gSManager;
}

GameStateManager& Object::gameStateManager()
{
	return gSManager;
}

Texture& Object::getMenuTexture()
{
	return menuTexture;
}

Texture& Object::getDeadTexture()
{
	return deadTexture;
}

Texture& Object::getTutorialTexture()
{
	return tutorialTexture;
}

Texture& Object::getTutorialButtonTexture() {
	return tutorialButtonTexture;
}

bool Object::getTutorialState() {
	return tutorialState;
}

void Object::setTutorialState(bool tutorialButtonState) {
	tutorialState = tutorialButtonState;
}

SDL_Texture* Object::ScoreTexture()
{
	return scoreTexture;
}

void Object::resetGame()
{
    bird = createBird();
	scrollingBackground = createScrollingBackground();
	reachFirstPipe = false;
	score = 0;
	tutorialState = false;
	// mScoreTexture = createScore( mFont, mScore );
}

bool detectCollision(Bird& bird, Scrolling& scrollingBackground)
{

    for (auto& background : scrollingBackground.getBackgrounds())
    {
        if (detectCollision(bird, background) || checkGroundCollision(bird)) {
			if (gameManager->moduleObject->getOnPlay()) {
				gameManager->moduleSound->playDead();
			}
            return true;
    	}
	}

    return false;
}

bool detectCollision1(SDL_Rect& left, SDL_Rect& right)
{
	return SDL_HasIntersection(&left, &right);
}

bool detectCollision(Bird& bird, std::pair<Background,float>& background)
{
    const auto& pipes = background.first.getPipes().getPipes();
    for (auto& pipe : pipes) {
		SDL_Rect rect = pipe.rect + background.second;
		SDL_Rect birdRect = bird.getRect();
        if (detectCollision1(birdRect, rect)) {
			//std::cout << "Rect:" << rect.x - bird.getRect().x << std::endl;
            return true;
        }
    }
    return false;
}

bool checkGroundCollision(Bird& bird)
{
	return bird.getRect().y + bird.getRect().h > 640 - 50 || bird.getRect().y < 0;
}