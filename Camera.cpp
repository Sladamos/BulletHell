#include "Camera.h"
#include "Game.h"
#include "Level.h"
#include "Shape.h"

MathPoint Camera::leftTopCorner = MathPoint();
MathPoint Camera::currentPlayerPosition = MathPoint();

MathPoint Camera::getObjectPositionOnScreen(const MathPoint& objectPosition)
{
	return MathPoint(objectPosition.getX() - leftTopCorner.getX(), objectPosition.getY() - leftTopCorner.getY());
}

MathPoint Camera::getPlayerPositionOnScreen()
{
	return MathPoint(calculatePlayerHorizontalPositionOnScreen(), calculatePlayerVerticalPositionOnScreen());
}

void Camera::setPlayerPosition(const MathPoint& playerPosition)
{
	currentPlayerPosition = playerPosition;
	actualizeLeftTopCorner();
}

void Camera::actualizeLeftTopCorner()
{
	actualizeHorizontalCornerPosition();
	actualizeVerticalCornerPosition();
}

void Camera::actualizeHorizontalCornerPosition()
{
	if (isPlayerNearTheLeftBorder())
		leftTopCorner.setX(0);
	else if (isPlayerNearTheRightBorder())
		leftTopCorner.setX(Level::width - (Game::screenWidth - Painter::statsWidth));
	else
		leftTopCorner.setX(currentPlayerPosition.getX() - (Game::screenWidth - Painter::statsWidth) / 2);
}

void Camera::actualizeVerticalCornerPosition()
{
	if (isPlayerNearTheTopBorder())
		leftTopCorner.setY(0);
	else if (isPlayerNearTheBottomBorder())
		leftTopCorner.setY(Level::height - Game::screenHeight);
	else
		leftTopCorner.setY(currentPlayerPosition.getY() - Game::screenHeight / 2);
}

int Camera::calculatePlayerHorizontalPositionOnScreen()
{
	int horizontalPlayerPosition;
	if (isPlayerNearTheRightBorder() || isPlayerNearTheLeftBorder())
		horizontalPlayerPosition = currentPlayerPosition.getX() - leftTopCorner.getX();
	else
		horizontalPlayerPosition = (Game::screenWidth - Painter::statsWidth) / 2;
	return horizontalPlayerPosition;
}

int Camera::calculatePlayerVerticalPositionOnScreen()
{
	int verticalPlayerPosition;
	if (isPlayerNearTheTopBorder() || isPlayerNearTheBottomBorder())
		verticalPlayerPosition = currentPlayerPosition.getY() - leftTopCorner.getY();
	else
		verticalPlayerPosition = Game::screenHeight / 2;
	return verticalPlayerPosition;
}

bool Camera::isPlayerNearTheTopBorder()
{
	return currentPlayerPosition.getY() <= Game::screenHeight / 2;
}

bool Camera::isPlayerNearTheRightBorder()
{
	return Level::width - currentPlayerPosition.getX() <= (Game::screenWidth - Painter::statsWidth) / 2;
}

bool Camera::isPlayerNearTheBottomBorder()
{
	return Level::height - currentPlayerPosition.getY() <= Game::screenHeight / 2;
}

bool Camera::isPlayerNearTheLeftBorder()
{
	return currentPlayerPosition.getX() <= (Game::screenWidth - Painter::statsWidth) / 2;
}

bool Camera::isObjectInRange(GameObject* gameObject)
{
	Shape* objectShape = gameObject->getShape();
	return 
		objectShape->getMostBottomCoordinate() + gameObject->getPosition().getY() >= leftTopCorner.getY() &&
		objectShape->getMostTopCoordinate() + gameObject->getPosition().getY() <= leftTopCorner.getY() + Game::screenHeight &&
		objectShape->getMostRightCoordinate() + gameObject->getPosition().getX() >= leftTopCorner.getX() &&
		objectShape->getMostLeftCoordinate() + gameObject->getPosition().getX() <= leftTopCorner.getX() + Game::screenWidth - Painter::statsWidth;
}
