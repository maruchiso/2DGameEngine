#include "Player.h"
#include "lib.h"
#include "Tear.h"



Player::Player(int x, int y, int w, int h) : rect{ x, y, w, h }, xVelocity(0), yVelocity(0) {}

void Player::handleEvent(SDL_Event& e, std::vector<Tear>& tears) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		case SDLK_w:    yVelocity -= playerSpeed; break;
		case SDLK_s:  yVelocity += playerSpeed; break;
		case SDLK_d: xVelocity += playerSpeed; break;
		case SDLK_a:  xVelocity -= playerSpeed; break;
		}
	}

	if (e.type == SDL_KEYUP && e.key.repeat == 0) {

		switch (e.key.keysym.sym) {
		case SDLK_w:    yVelocity += playerSpeed; break;
		case SDLK_s:  yVelocity -= playerSpeed; break;
		case SDLK_d: xVelocity -= playerSpeed; break;
		case SDLK_a:  xVelocity += playerSpeed; break;
		}
	}

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP:
			tears.push_back(Tear(rect.x, rect.y, rect.w, rect.h, 0, -tearSpeed)); break;
		case SDLK_DOWN:
			tears.push_back(Tear(rect.x, rect.y, rect.w, rect.h, 0, tearSpeed)); break;
		case SDLK_RIGHT:
			tears.push_back(Tear(rect.x, rect.y, rect.w, rect.h, tearSpeed, 0)); break;
		case SDLK_LEFT:
			tears.push_back(Tear(rect.x, rect.y, rect.w, rect.h, -tearSpeed, 0)); break;
		}
	}

	
}


void Player::update(std::vector<char> directionList) {

	bool canMoveRight = std::find(directionList.begin(), directionList.end(), 'R') != directionList.end();
	bool canMoveUp = std::find(directionList.begin(), directionList.end(), 'U') != directionList.end();
	bool canMoveLeft = std::find(directionList.begin(), directionList.end(), 'L') != directionList.end();
	bool canMoveDown = std::find(directionList.begin(), directionList.end(), 'D') != directionList.end();

	//Move on X axis
	if (canMoveRight) {
		if (xVelocity < 0) rect.x += xVelocity;
	}
	else if (canMoveLeft) {
		if (xVelocity > 0) rect.x += xVelocity;
	}
	else rect.x += xVelocity;

	//Move on Y axis
	if (canMoveUp) {
		if (yVelocity > 0) rect.y += yVelocity;
	}
	else if (canMoveDown) {
		if (yVelocity < 0) rect.y += yVelocity;
	}
	else rect.y += yVelocity;


	if (rect.x < 0) rect.x = 0;
	if (rect.x + rect.w > WINDOW_WIDTH) rect.x = WINDOW_WIDTH - rect.w;
	if (rect.y < 0) rect.y = 0;
	if (rect.y + rect.h > WINDOW_HEIGHT) rect.y = WINDOW_HEIGHT - rect.h;

}



void Player::render(SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 0, 255, 255, 255);
	SDL_RenderFillRect(ren, &rect);
}


SDL_Rect Player::getPlayer() {
	return rect;
}