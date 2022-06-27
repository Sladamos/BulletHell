#include "Player.h"

Player::Player(std::string objectName) : GameObject(objectName), speed(1.0), distance(0.0) {}

void Player::action(double timeGain)
{
	distance += speed * timeGain;
	position.setCoordinates(Constans::screenWidth / 2 + sin(distance) * Constans::screenHeight / 3,
							Constans::screenHeight / 2 + cos(distance) * Constans::screenHeight / 3);	//TODO refactor movement - its template action
}

void Player::setSpeed(double speed)
{
	this->speed = speed;
}