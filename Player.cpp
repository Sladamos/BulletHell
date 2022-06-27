#include "Player.h"

Player::Player(std::string objectName) : GameObject(objectName), speed(1.0), distance(0.0) {}

void Player::action(double timeGain)
{
	distance += speed * timeGain;
	position.setCoordinates(SCREEN_WIDTH / 2 + sin(distance) * SCREEN_HEIGHT / 3,
							SCREEN_HEIGHT / 2 + cos(distance) * SCREEN_HEIGHT / 3);	//TODO template action - refactor
}


void Player::setSpeed(double speed)
{
	this->speed = speed;
}