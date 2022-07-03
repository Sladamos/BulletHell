#include "Camera.h"
#include "Constants.h"
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
		leftTopCorner.setX(Constants::levelWidth - (Constants::screenWidth - Constants::statsWidth));
	else
		leftTopCorner.setX(currentPlayerPosition.getX() - (Constants::screenWidth - Constants::statsWidth) / 2);
}

void Camera::actualizeVerticalCornerPosition()
{
	if (isPlayerNearTheTopBorder())
		leftTopCorner.setY(0);
	else if (isPlayerNearTheBottomBorder())
		leftTopCorner.setY(Constants::levelHeight - Constants::screenHeight);
	else
		leftTopCorner.setY(currentPlayerPosition.getY() - Constants::screenHeight / 2);
}

int Camera::calculatePlayerHorizontalPositionOnScreen()
{
	int horizontalPlayerPosition;
	if (isPlayerNearTheRightBorder() || isPlayerNearTheLeftBorder())
		horizontalPlayerPosition = currentPlayerPosition.getX() - leftTopCorner.getX();
	else
		horizontalPlayerPosition = (Constants::screenWidth - Constants::statsWidth) / 2;
	return horizontalPlayerPosition;
}

int Camera::calculatePlayerVerticalPositionOnScreen()
{
	int verticalPlayerPosition;
	if (isPlayerNearTheTopBorder() || isPlayerNearTheBottomBorder())
		verticalPlayerPosition = currentPlayerPosition.getY() - leftTopCorner.getY();
	else
		verticalPlayerPosition = Constants::screenHeight / 2;
	return verticalPlayerPosition;
}

bool Camera::isPlayerNearTheTopBorder()
{
	return currentPlayerPosition.getY() <= Constants::screenHeight / 2;
}

bool Camera::isPlayerNearTheRightBorder()
{
	return Constants::levelWidth - currentPlayerPosition.getX() <= (Constants::screenWidth - Constants::statsWidth) / 2;
}

bool Camera::isPlayerNearTheBottomBorder()
{
	return Constants::levelHeight - currentPlayerPosition.getY() <= Constants::screenHeight / 2;
}

bool Camera::isPlayerNearTheLeftBorder()
{
	return currentPlayerPosition.getX() <= (Constants::screenWidth - Constants::statsWidth) / 2;
}

bool Camera::isObjectInRange(GameObject* gameObject)
{
	Shape* objectShape = gameObject->getShape();
	return 
		objectShape->getMostBottomCoordinate() + gameObject->getPosition().getY() >= leftTopCorner.getY() &&
		objectShape->getMostTopCoordinate() + gameObject->getPosition().getY() <= leftTopCorner.getY() + Constants::screenHeight &&
		objectShape->getMostRightCoordinate() + gameObject->getPosition().getX() >= leftTopCorner.getX() &&
		objectShape->getMostLeftCoordinate() + gameObject->getPosition().getX() <= leftTopCorner.getX() + Constants::screenWidth - Constants::statsWidth;
}
