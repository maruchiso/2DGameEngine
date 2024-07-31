#pragma once
#include "Player.h"
#include "Object.h"

bool isCollision(Player& player, Object& object);
char directionOfCollision(Player& p, Object& o, bool col);
void eraseTearIfCollision(std::vector<Tear>& tears, std::vector<Object>& objects);