#pragma once
#include "Point.h"
#include "Player.h"
class Camera
{
public:
	static void setPlayerPosition(const Point& playerPosition);
	static Point getObjectPositionOnScreen (const Point& objectPosition);
	static Point getPlayerPositionOnScreen();
private:
	static void actualizeLeftTopCorner();
	static void actualizeHorizontalCornerPosition();
	static void actualizeVerticalCornerPosition();
	static int calculatePlayerHorizontalPositionOnScreen();
	static int calculatePlayerVerticalPositionOnScreen();
	static bool isPlayerNearTheTopBorder();
	static bool isPlayerNearTheRightBorder();
	static bool isPlayerNearTheBottomBorder();
	static bool isPlayerNearTheLeftBorder();

	static Point currentPlayerPosition;
	static Point leftTopCorner;
};

