#pragma once
#include "Object.h"
#include <iostream>
#include <SDL.h>
#include <map>
#include <vector>
#include "const.h"
#include "Tear.h"

class Player
{
public:
	Player(int x, int y, int w, int h);
	void handleEvent(SDL_Event& e, std::vector<Tear>& tears);
	void update(std::vector<char> directionList);
	void render(SDL_Renderer* ren);
	SDL_Rect getPlayer();
	int getHP();
	int changeHP();



private:
	SDL_Rect rect;
	int xVelocity, yVelocity;
	int playerSpeed = 10;
	int tearSpeed = 20;
	int hp = 100;



};