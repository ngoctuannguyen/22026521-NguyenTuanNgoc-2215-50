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
// SDL_Texture* createScore(TTF_Font* font, int score = 0);
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

Pipes createPipes()
{	
	SDL_Renderer* renderer = gameManager->moduleRenderer->getRenderer();
	Texture texture("src2/assets/textures/pipe.png", renderer);
	std::vector<Pipe> pipes(8);

	static bool firstScroll = false;

	Pipes pipesObj(texture, pipes);

	for (int i = 0, x = 0; i < pipes.size(); i += 2, x += 200) {
		pipes[i] = {(SDL_Rect) {x, 0, 50, 200}, true};
		pipes[i + 1] = {(SDL_Rect) {x, 390, 50, 200}, false};
	}

	pipesObj.resetHeight(pipes);

	for (int i = 0, x = 0; i < pipes.size(); i += 2, x += 200) {
		if (i == 0 || i == 2 && !firstScroll) {
			pipes[i] = {(SDL_Rect) {x, 0, 50, 0}, true};
			pipes[i + 1] = {(SDL_Rect) {x, 390, 50, 0}, false};
		}
		std::cout << pipes[i].rect.h << " " << pipes[i + 1].rect.h << std::endl;
	}

	firstScroll = true;

	return Pipes(texture, pipes);
}

Scrolling createScrollingBackground()
{
	const Pipes pipes = createPipes();
	SDL_Renderer* renderer = gameManager->moduleRenderer->getRenderer();
	Texture baseTexture("src2/assets/textures/base.png", renderer);
	Texture backgroundTexture("src2/assets/textures/background.png", renderer);
	Background backgrounds({{backgroundTexture, {0, 0, 800, 640}},
			{baseTexture, {0, 590, 800, 50}}}, pipes);

	int pipeGap = 150;

	return Scrolling({{backgrounds, 0}, {backgrounds, 800}});
}

Object::Object() :

	bird(createBird()),
	scrollingBackground(createScrollingBackground()),
	menuTexture(Texture("src2/assets/textures/menu.png", gameManager->moduleRenderer->getRenderer())),
	deadTexture(Texture("src2/assets/textures/gameover.png", gameManager->moduleRenderer->getRenderer())),
	// font(TTF_OpenFont("src2/assets/fonts/font.ttf", 40 )),
	// scoreTexture(createScore(font, 0)),
	score(0),
	xMoved(0),
	soundTexture(Texture("src2/assets/textures/sound.png", gameManager->moduleRenderer->getRenderer())),
	onPlay(true)

{}

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
	if (onPlay == true) {
		Mix_Resume(-1);
	}
	else {
		Mix_Pause(-1);
	}
}

bool Object::update()
{
	if(gSManager.getGameState() != PLAY)
		return true;

	float deltaTime = gameManager->moduleTimer->getDeltaTime();

	// std::cout << deltaTime << std::endl;

    bird.updateYPos(deltaTime); 

	float xMove = 1.0f * deltaTime;
	// float xMove = 0.2f;
	xMoved += xMove;

	// std::cout << xMoved << std::endl;
	
	if(!reachFirstPipe)
	{
		if(xMoved >= 400.0f)
		{
			reachFirstPipe = true;
			xMoved = 0.0f;
		}
	}
	else if(xMoved >= 180.0f)
	{
		score++;
		gameManager->moduleSound->playScore();
		xMoved = 0.0f;
		// scoreTexture = createScore(font, score);
	}


	///std::cout << scrollingBackground.getBackgrounds().size() << std::endl;

	scrollingBackground.move(xMove, -800.0f, 800.0f);

	if(detectCollision(bird, scrollingBackground)) {
		std::cout << "Collision!" << std::endl;
		gSManager.setGameState(DEAD);
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
	// mScoreTexture = createScore( mFont, mScore );
}

bool detectCollision(Bird& bird, Scrolling& scrollingBackground)
{

    for (auto& background : scrollingBackground.getBackgrounds())
    {
        if (detectCollision(bird, background) || checkGroundCollision(bird)) {
			gameManager->moduleSound->playDead();
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

// SDL_Texture* createScore(TTF_Font* font, int score)
// {
// 	std::string result = "SCORE: " + std::to_string(score);
// 	SDL_Renderer* renderer = gameManager->moduleRenderer->getRenderer();
// 	auto surfaceMessage = TTF_RenderText_Solid(font, result.c_str(), {255, 255, 255});
// 	return SDL_CreateTextureFromSurface(renderer, surfaceMessage);
// }

bool checkGroundCollision(Bird& bird)
{
	return bird.getRect().y + bird.getRect().h > 640 - 50 || bird.getRect().y < 0;
}