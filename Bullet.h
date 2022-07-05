#pragma once
#include <string>
#include "GameObject.h"
#include "Moveable.h"
#include "MathPoint.h"
class Bullet : public GameObject, public Moveable
{
public:
	Bullet(std::string objectName, const MathPoint& position, int damageDealt, int radius);
	void action(double timeGain) override;
private:
	bool shouldBeDestroyed() override;

	constexpr static int maxRange = 400;
	int damageDealt, currentDistance;
	MathPoint launchPosition;
};