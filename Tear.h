#pragma once
#include <SDL.h>

class Tear
{
public:
	Tear(int x, int y, int w, int h, int xVelocity, int yVelocity);
	void render(SDL_Renderer* ren);
	SDL_Rect getTear();
	void update();

private:
	SDL_Rect rect;
	int xVelocity, yVelocity;
};

