#pragma once
#include "MathPoint.h"
#include "AnimationTimer.h"
#include "Game.h"
class GameObject;
class Moveable
{
public:
	Moveable(int numberOfFrames);
	Moveable(double horizontalSpeed, double verticalSpeed, double animationTime, int numberOfFrames);
	Moveable(double horizontalSpeed, double verticalSpeed);
	virtual ~Moveable();
	void setVerticalSpeed(double verticalSpeed);
	void setHorizontalSpeed(double horizontalSpeed);
	virtual void undoVerticalMove(double timeGain) = 0;
	virtual void undoHorizontalMove(double timeGain) = 0;
	virtual void repairMove(GameObject* collidableObject, double timeGain);
protected:
	void move(double timeGain, MathPoint& position);
	void undoVerticalMove(double timeGain, MathPoint& position);
	void undoHorizontalMove(double timeGain, MathPoint& position);
	int getCurrentFrameNumber();
	
	double horizontalSpeed, verticalSpeed;
private:
	AnimationTimer* animationTimer;
	static constexpr int horizontalSpeedMultiplier = (Game::screenWidth / 4);
	static constexpr int verticalSpeedMultiplier = (Game::screenHeight / 3);
};

