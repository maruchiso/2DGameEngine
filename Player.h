#pragma once
#include "Object.h"
#include <iostream>
#include <SDL.h>
#include <map>
#include <vector>
#include "const.h"

class Player
{
public:
	Player(int x, int y, int w, int h);
	void handleEvent(SDL_Event& e);
	void update(std::vector<char> directionList);
	void render(SDL_Renderer* ren);
	SDL_Rect getPlayer();



private:
	SDL_Rect rect;
	int xVelocity, yVelocity;
	int playerSpeed = 10;


};