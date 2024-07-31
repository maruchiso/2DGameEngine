#include "HealthBar.h"

HealthBar::HealthBar(int x, int y, int w, int h, int maxHealth) :
	background{ x, y, w, h }, health{ x, y, w, h}, maxHealth(maxHealth), currentHealth(maxHealth) {}

void HealthBar::setHealth(int health) {

}