#include "HealthBar.h"

HealthBar::HealthBar(int x, int y, int w, int h, int maxHealth) :
	background{ x, y, w, h }, health{ x, y, w, h}, maxHealth(maxHealth), currentHealth(maxHealth) {}

void HealthBar::setHealth(int health) {
	currentHealth = health;
}

void HealthBar::render(SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 128, 128, 128, 255);
	SDL_RenderFillRect(ren, &background);
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	SDL_RenderFillRect(ren, &health);
}