#pragma once
#include "Player.h"
#include "Object.h"

bool isCollision(Player& player, Object& object);
char directionOfCollision(Player& p, Object& o, bool col);