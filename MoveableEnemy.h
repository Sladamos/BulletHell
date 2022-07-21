#pragma once
#include "Enemy.h"
#include "Moveable.h"
#include "ChangesTimer.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class MoveableEnemy : public Enemy, public Moveable
{
public:
	MoveableEnemy(const std::string& objectName, int numberOfFrames, const MathPoint& startingPoint, const std::vector<MathPoint>& corners, double shootingPeriod, int hitpoints);
	virtual ~MoveableEnemy();
	void undoHorizontalMove(double timeGain) override;
	void undoVerticalMove(double timeGain) override;
	void action(double timeGain) override;
	void print(Painter* painter) override;

	static constexpr double enemySpeedMultiplier = 1;
private:
	double generateRandomSpeed();

	ChangesTimer* speedChangingTimer;
	double maximumSpeed;
};
