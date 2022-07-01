#include "Player.h"
#include "Camera.h"
#include "Painter.h"
#include "BmpManager.h"

Player::Player(std::string objectName, const std::vector<Point>& corners) :
	GameObject(objectName, Point(100, 100), corners), Moveable(), hitpoints(playerMaxHealth)
{
	Camera::setPlayerPosition(position);
}

int Player::getHitpoints()
{
	return hitpoints;
}

void Player::action(double timeGain)
{
	Moveable::straightMove(timeGain, position);
	Camera::setPlayerPosition(position);
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

void Player::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), Camera::getPlayerPositionOnScreen());	
}
