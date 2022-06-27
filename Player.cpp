#include "Player.h"
Player::Player(std::string objectName) : GameObject(objectName, Point(100, 100)),
										 horizontalSpeed(0.0), verticalSpeed(0.0) {}
void Player::action(double timeGain)
{
	position.moveByVector(horizontalSpeed * timeGain * Constants::horizontalSpeedMultiplier,
							verticalSpeed * timeGain * Constants::verticalSpeedMultiplier);	
	checkHorizontalBorders();
	checkVerticalBorders();	//TODO: check is there an collision with other object or world borders (implement that in world maybe? if moveable?)
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

void Player::checkHorizontalBorders()
{/*
	if (position.getX() - playerWidth / 2 < 0)
		position.setX();
	else if (position.getX() + playerWidth / 2 > Constants::levelWidth)
		position.setX();*/
}

void Player::checkVerticalBorders()
{/*
	if (position.getY() - playerHeight / 2 < 0)
		position.setY();
	else if (position.getY() + playerHeight / 2 > Constants::levelHeight)
		position.setY();*/
}

void Player::setHorizontalSpeed(double horizontalSpeed)
{
	this->horizontalSpeed = horizontalSpeed;
}

void Player::setVerticalSpeed(double verticalSpeed)
{
	this->verticalSpeed = verticalSpeed;
}