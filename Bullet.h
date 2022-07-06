#pragma once
#include <string>
#include "GameObject.h"
#include "Moveable.h"
#include "MathPoint.h"
class Bullet : public GameObject, public Moveable
{
public:
	Bullet(std::string objectName, const MathPoint& position, int damageDealt, int radius);
	Bullet(std::string objectName, const MathPoint& position, int radius);
	void action(double timeGain) override;
private:
	bool shouldBeDestroyed() override;
	bool isOutOfRange();

	constexpr static int maxRange = 400;
	constexpr static int defaultDamage = 10;
	int damageDealt;
	bool toDestroy;
	MathPoint launchPosition;
};