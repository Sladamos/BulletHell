#include "Player.h"
#include "Camera.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Level.h"
#include "Bullet.h"

int Player::scoreValue = 0;

Player::Player(const std::string& objectName, int numberOfFrames, const std::vector<MathPoint>& corners) :
	GameObject(objectName, MathPoint(100, 100), corners, playerMaxHealth, numberOfFrames), Moveable(numberOfFrames),
	Shootable(0.2), fireButtonIsPressed(false)
{
	scoreValue = 0;
	invicibilityTimer = new InvicibilityTimer(0.5);
	scoreMagnitudeTimer = new ScoreMagnitudeTimer(2);
	Camera::setPlayerPosition(position);
	BmpManager::loadStaticBitmap(invicibilityFrame, 60);
}

int Player::getScoreValue()
{
	return scoreValue;
}

bool Player::isInpenetrableBy(GameObject* gameObject)
{
	if (gameObject->isEnemy() || gameObject->isUnholyBullet() && !invicibilityTimer->canBeDamaged())
		return true;
	return false;
}

bool Player::doesGetDamagedBy(GameObject* gameObject)
{
	if (gameObject->isUnholyBullet() && invicibilityTimer->canBeDamaged())
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

bool Player::shouldBeDestroyed()
{
	return hitpoints <= 0;
}

void Player::setPosition(const MathPoint& position)
{
	GameObject::setPosition(position);
	Camera::setPlayerPosition(position);
}

void Player::action(double timeGain)
{
	move(timeGain, position);
	Camera::setPlayerPosition(position);
	if (fireButtonIsPressed)
		shootIfPossible(&Shootable::multipleShooting);
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

void Player::print(Painter* painter)
{
	if(!invicibilityTimer->canBeDamaged())
		painter->drawObject(BmpManager::getBitmap(invicibilityFrame), Camera::getPlayerPositionOnScreen());
	painter->drawObject(BmpManager::getAnimation(objectName, getCurrentFrameNumber()), Camera::getPlayerPositionOnScreen());	
}

void Player::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addGameObject(new Bullet("./gfx/holyBullet", this, position, horizontalSpeed*Bullet::speedMultiplier, verticalSpeed*Bullet::speedMultiplier));
}

void Player::updateViewingAngle()
{
	int horizontalSign = horizontalSpeed == 0 ? 0 : horizontalSpeed / abs(horizontalSpeed);
	int verticalSign = verticalSpeed == 0 ? 0 : verticalSpeed / abs(verticalSpeed);

	if (verticalSign != 0)
		Shootable::setViewingAngle((90 - 45 * horizontalSign) * verticalSign);
	else if (horizontalSign != 0)
		Shootable::setViewingAngle(90 - 90 * horizontalSign);
}

void Player::setShootingPermission(bool fireButtonIsPressed)
{
	this->fireButtonIsPressed = fireButtonIsPressed;
}

void Player::decreaseHitpoints(int damageDealt)
{
	GameObject::decreaseHitpoints(damageDealt);
	invicibilityTimer->resetTimer();
}

void Player::decreaseScore(int value)
{
	scoreValue = scoreValue - value < 0 ? 0 : scoreValue - value;
}

void Player::increaseScore(int value)
{
	scoreValue += value * scoreMagnitudeTimer->getMagnitude();
	scoreMagnitudeTimer->increaseMagnitude();
	scoreMagnitudeTimer->resetTimer();
}

Player::~Player()
{
	delete invicibilityTimer;
	delete scoreMagnitudeTimer;
}