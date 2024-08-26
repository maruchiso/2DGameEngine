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

void eraseTearIfCollision(std::vector<Tear>& tears, std::vector<Object>& objects) {
	
	for (auto it = tears.begin(); it != tears.end(); ){
		bool paramIsCollision = false;
		for (Object obj : objects) {
			SDL_Rect object, tear;
			object = obj.getObject();
			tear = it->getTear();
			if ((object.x + object.w >= tear.x &&
				tear.x + tear.w >= object.x &&
				object.y + object.h >= tear.y &&
				tear.y + tear.h >= object.y) || (
					tear.x < 0 || tear.x + tear.w > WINDOW_WIDTH ||
					tear.y < 0 || tear.y + tear.h > WINDOW_HEIGHT)) {
				std::cout << "KOLIZJA" << std::endl;
				paramIsCollision = true;
				break;
			}
		}

		if (paramIsCollision) {
			it = tears.erase(it);
		}
		else {
			it++;
		}
	}
}

//TODO:
//I have to add to object param that describes if it:
//hp++, hp--, or only collision

//Generate random room
//generate random map
//Opponents