#include "Player.h"
#include "Camera.h"
#include "Painter.h"
#include "BmpManager.h"

Player::Player(std::string objectName, const std::vector<MathPoint>& corners) :
	GameObject(objectName, MathPoint(100, 100), corners), Moveable(), hitpoints(playerMaxHealth)
{
	Camera::setPlayerPosition(position);
}

void Player::setPosition(const MathPoint& position)
{
	GameObject::setPosition(position);
	Camera::setPlayerPosition(position);
}

int Player::getHitpoints()
{
	return hitpoints;
}

void Player::action(double timeGain)
{
	move(timeGain, position);
	Camera::setPlayerPosition(position);
}

void Player::undoHorizontalMove(double timeGain)
{
	Moveable::undoHorizontalMove(timeGain, position);
	Camera::setPlayerPosition(this->position);
}

void Player::undoVerticalMove(double timeGain)
{
	Moveable::undoVerticalMove(timeGain, position);
	Camera::setPlayerPosition(this->position);
}

bool Player::isInpenetrableBy(GameObject* gameObject)
{
	if (gameObject->isEnemy())
		return true;
	return false;
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
