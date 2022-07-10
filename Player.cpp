#include "Player.h"
#include "Camera.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Level.h"
#include "HolyBullet.h"

Player::Player(const std::string& objectName, const std::vector<MathPoint>& corners) :
	GameObject(objectName, MathPoint(100, 100), corners, playerMaxHealth), Moveable(), Shootable(0.2), fireButtonIsPressed(false)
{
	invicibilityTimer = new InvicibilityTimer(0.5);
	TimeManager::addTimer(invicibilityTimer);
	Camera::setPlayerPosition(position);
	BmpManager::loadStaticBitmap(invicibilityFrame, 60);
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

bool Player::isInpenetrableBy(GameObject* gameObject)
{
	if (gameObject->isEnemy() || gameObject->isUnholyBullet() && !invicibilityTimer->canBeDamaged())
		return true;
	return false;
}

bool Player::isDamagableBy(GameObject* gameObject)
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

void Player::print(Painter* painter)
{
	if(!invicibilityTimer->canBeDamaged())
		painter->drawObject(BmpManager::getBitmap(invicibilityFrame), Camera::getPlayerPositionOnScreen());
	painter->drawObject(BmpManager::getBitmap(objectName), Camera::getPlayerPositionOnScreen());	
}

void Player::createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed)
{
	Level::addBullet(new HolyBullet(position, horizontalSpeed, verticalSpeed));
}

void Player::updateViewingAngle()
{
	int horizontalSign = horizontalSpeed == 0 ? 0 : horizontalSpeed / abs(horizontalSpeed);
	int verticalSign = verticalSpeed == 0 ? 0 : verticalSpeed / abs(verticalSpeed);

	if (verticalSign != 0)
		viewingAngle = (90 - 45 * horizontalSign) * verticalSign;
	else if (horizontalSign != 0)
		viewingAngle = 90 - 90 * horizontalSign;
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

Player::~Player()
{
	delete invicibilityTimer;
}