#include "Player.h"

Player::Player(std::string objectName, const std::vector<Point>& corners) : 
	MoveableObject(objectName, Point(100, 100), corners) {}

void Player::action(double timeGain)
{
	MoveableObject::basicMove(timeGain);	//TODO: rename from basic na po linii prostej
}

bool Player::stoppedVertically(const SDL_Event& event)
{
	if (event.key.keysym.sym == SDLK_UP && verticalSpeed < 0 ||
		event.key.keysym.sym == SDLK_DOWN && verticalSpeed > 0)
		return true;
	return false;
}

bool Player::stoppedHorizontally(const SDL_Event& event)
{
	if (event.key.keysym.sym == SDLK_LEFT && horizontalSpeed < 0 ||
		event.key.keysym.sym == SDLK_RIGHT && horizontalSpeed > 0)
		return true;
	return false;
}
