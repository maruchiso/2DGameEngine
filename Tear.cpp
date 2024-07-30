#include "Tear.h"
#include "lib.h"

Tear::Tear(int x, int y, int w, int h, int xVel, int yVel) : rect{ x, y, w, h}, xVelocity(xVel), yVelocity(yVel){}

SDL_Rect Tear::getTear() {
	return rect;
}

void Tear::render(SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 10, 76, 125, 255);
	SDL_RenderFillRect(ren, &rect);
}

void Tear::update() {
	rect.x += xVelocity;
	rect.y += yVelocity;
}