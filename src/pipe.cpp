#include "header/pipe.h"
#include <ctime>
#include <iostream>

Pipe::Pipe()
{
	pipeWidth = 80;
	pipeHeight = 360;
	space = 190;
}

Pipe::Pipe(int x_pos)
{
	srand(time(NULL));
	xPipe[x_pos] = (x_pos + 4) * 320;
    pipe_height[x_pos] = Pipe::pipeRandHeight();
	p2h[x_pos] = pipe_height[x_pos] + space;
	setDest(xPipe[x_pos], pipe_height[x_pos] - pipeHeight, pipeWidth, pipeHeight);
}

int Pipe::pipeRandHeight()
{
	return rand() * rand() % (330 - 100 + 1) + 100;
}

void Pipe::PipeUpdate1(int i, bool birdDie)
{
	if (xPipe[i] <= -pipeWidth)
	{
	    pipe_height[i] = Pipe::pipeRandHeight();
		xPipe[i] = 880;
	}
	else
	{
		if(!birdDie) {
		    xPipe[i]--;
		//setSrc(0, 0, 125, 500);
        }
		setDest(xPipe[i], pipe_height[i] - pipeHeight, pipeWidth, pipeHeight);
	}
}

void Pipe::PipeUpdate2(int i)
{
	p2h[i] = pipe_height[i] + space;
	setSrc(0, 0, 125, 500);
	setDest(xPipe[i], p2h[i], pipeWidth, pipeHeight);
}

int Pipe::getPipeHeight(int i)
{
	return pipe_height[i];
}

int Pipe::getXPipe(int i)
{
	return xPipe[i];
}

void Pipe::SpaceScore(int i)
{
	setSrc(0, 0, NULL, NULL);
	//setSrc(0, 0, 78, 69);	//test spaceScore
	setDest(xPipe[i] + 20, pipe_height[i], 3, space);
}

void Pipe::Render(SDL_Renderer*& ren)
{	
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
	SDL_RenderPresent(ren);
}

void Pipe::movePipeToLeft(int i) {
    xPipe[i]--;
}

