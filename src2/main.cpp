#include <SDL2/SDL.h>
#include "header/gamemanager.h"

Manager* gameManager;

int main(int argc, char* argv[])
{
	gameManager = new Manager();
	gameManager->play();
	return 0;
}