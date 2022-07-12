#pragma once
#include "Enemy.h"
#include "Moveable.h"
#include "ChangesTimer.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class MoveableEnemy : public Enemy, public Moveable
{
public:
	MoveableEnemy(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners, double shootingPeriod, int hitpoints);
	virtual ~MoveableEnemy();
	void undoHorizontalMove(double timeGain) override;
	void undoVerticalMove(double timeGain) override;
	virtual void action(double timeGain);

	static constexpr double enemySpeedMultiplier = 1.5;
private:
	double generateRandomSpeed();

	ChangesTimer* speedChangingTimer;
	double maximumSpeed;
};
