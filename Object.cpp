#include "Object.h"
#include "lib.h"

Object::Object(int x, int y, int w, int h) : rect{ x, y, w, h } {};

void Object::render(SDL_Renderer* ren) {

	SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
	SDL_RenderFillRect(ren, &rect);
}

SDL_Rect Object::getObject() {
	return rect;
}