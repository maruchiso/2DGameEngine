#pragma once
#include "Player.h"
#include <iostream>
#include <SDL.h>
#include <map>
#include "const.h"

class Object
{
public:
	Object(int x, int y, int w, int h);
	void render(SDL_Renderer* ren);
	SDL_Rect getObject();

private:
	SDL_Rect rect;

};
