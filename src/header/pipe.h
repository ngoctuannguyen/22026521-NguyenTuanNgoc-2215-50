#pragma once
#include "object.h"
#include <ctime>

static int pipe_height[3];		//Height of the up pipe
static int xPipe[3];		//Distance of pipes

class Pipe : public Object {
private:
public:
	int pipeWidth;
	int pipeHeight;
	int space;

	int p2h[3];
	Pipe();
	Pipe(int x_pos);
	int pipeRandHeight();
	void PipeUpdate1(int i, bool birdDie);
	void PipeUpdate2(int i);
	int getPipeHeight(int i);
	int getXPipe(int i);
	void SpaceScore(int i);
	void Render(SDL_Renderer*& ren);
    void movePipeToLeft(int i);
	void pipeRender();
};