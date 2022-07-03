#pragma once
#include "MathPoint.h"
#include "Player.h"
class Camera
{
public:
	static void setPlayerPosition(const MathPoint& playerPosition);
	static MathPoint getObjectPositionOnScreen (const MathPoint& objectPosition);
	static MathPoint getPlayerPositionOnScreen();
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

	static MathPoint currentPlayerPosition;
	static MathPoint leftTopCorner;
};

