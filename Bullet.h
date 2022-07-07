#pragma once
#include <string>
#include "GameObject.h"
#include "Moveable.h"
#include "MathPoint.h"
class Bullet : public GameObject, public Moveable
{
public:
	Bullet(const std::string& objectName, const MathPoint& position, int damageDealt, int radius, double horizontalSpeed, double verticalSpeed);
	Bullet(const std::string& objectName, const MathPoint& position, int radius, double horizontalSpeed, double verticalSpeed);
	void action(double timeGain) override;
	void repairMove(GameObject* collidableObject, double timeGain) override;
	void undoVerticalMove(double timeGain) override {};
	void undoHorizontalMove(double timeGain) override {};
	void hit(GameObject* targetObject);

	static double constexpr bulletSpeedMultiplier = 2;
private:
	bool shouldBeDestroyed() override;
	bool isOutOfRange();

	constexpr static int maxRange = 400;
	constexpr static int defaultDamage = 10;
	int damageDealt;
	bool toDestroy;
	MathPoint launchPosition;
};