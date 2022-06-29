#include "Camera.h"
#include "Constants.h"

Point Camera::leftTopCorner = Point();
Point Camera::currentPlayerPosition = Point();

Point Camera::getObjectPositionOnScreen(const Point& objectPosition)
{
	return Point(objectPosition.getX() - leftTopCorner.getX(), objectPosition.getY() - leftTopCorner.getY());
}

Point Camera::getPlayerPositionOnScreen()
{
	return Point(calculatePlayerHorizontalPositionOnScreen(), calculatePlayerVerticalPositionOnScreen());
}

void Camera::setPlayerPosition(const Point& playerPosition)
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
