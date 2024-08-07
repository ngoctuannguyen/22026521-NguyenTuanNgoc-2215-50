#pragma once
#include <vector>
#include "module.h"
#include "object.h"
#include "input.h"
#include "gamewindow.h"
#include "render.h"
#include "background.h"
#include "scroll.h"
#include "gamestatemanager.h"
#include "timer.h"
#include "sound.h"

class Manager {
private:
	std::vector<Module*> modules;
public:
	Manager();

	void initModules();
	void play();

	Input* moduleInput = NULL;
	GameWindow* moduleWindow = NULL;
	Renderer* moduleRenderer = NULL;
	Object* moduleObject = NULL;
	Timer* moduleTimer = NULL;
	Sound* moduleSound = NULL;
};

extern Manager* gameManager;

