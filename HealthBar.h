#pragma once
#include <SDL.h>
class HealthBar
{
public:
	HealthBar(int x, int y, int w, int h, int maxHealth);
	void setHealth(int health);
	void render(SDL_Renderer* ren);
private:
	SDL_Rect background, health;
	int maxHealth;
	int currentHealth;
};

