#include "collision.h"

bool isCollision(Player& p, Object& o)
{
	SDL_Rect object, player;
	object = o.getObject();
	player = p.getPlayer();

	if (object.x + object.w >= player.x &&
		player.x + player.w >= object.x &&
		object.y + object.h >= player.y &&
		player.y + player.h >= object.y) return true;
	else return false;
};
/*
R - right
L - left
U - up
D - down
(i can add enum here)
*/
char directionOfCollision(Player& p, Object& o, bool col) {

	if (!col) return 'N';

	SDL_Rect object, player;
	player = p.getPlayer();
	object = o.getObject();

	//find the lowest path between sides
	int right = player.x + player.w - object.x;
	int left = object.x + object.w - player.x;
	int down = player.y + player.h - object.y;
	int up = object.y + object.h - player.y;

	int minValue = std::min({ left, right, up, down });

	if (minValue == left) return 'L';
	else if (minValue == right) return 'R';
	else if (minValue == up) return 'U';
	else return 'D';
}