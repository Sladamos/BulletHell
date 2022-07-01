#pragma once
#include "Point.h"
#include "Player.h"
class Camera
{
public:
	static void setPlayerPosition(const Point& playerPosition);
	static Point getObjectPositionOnScreen (const Point& objectPosition);
	static Point getPlayerPositionOnScreen();
	static bool isPlayerNearTheTopBorder();
	static bool isPlayerNearTheRightBorder();
	static bool isPlayerNearTheBottomBorder();
	static bool isPlayerNearTheLeftBorder();
	static bool isObjectInRange(GameObject* object);
private:
	static void actualizeLeftTopCorner();
	static void actualizeHorizontalCornerPosition();
	static void actualizeVerticalCornerPosition();
	static int calculatePlayerHorizontalPositionOnScreen();
	static int calculatePlayerVerticalPositionOnScreen();

	static Point currentPlayerPosition;
	static Point leftTopCorner;
};

