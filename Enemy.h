#pragma once
#include "GameObject.h"
#include "Shootable.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class Enemy : public GameObject, public Shootable
{
public:
	Enemy(const std::string& objectName, const MathPoint& startingPoint, const std::vector<MathPoint>& corners, double shootingPeriod, int hitpoints);
	Enemy(const std::string& objectName, int numberOfFrames, const MathPoint& startingPoint, const std::vector<MathPoint>& corners, double shootingPeriod, int hitpoints);
	bool isInpenetrableBy(GameObject* gameObject) override;
	bool doesGetDamagedBy(GameObject* gameObject) override;
	bool shouldBeDestroyed() override;
private:
	void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;
};

