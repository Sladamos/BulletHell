#pragma once
#include "GameObject.h"
#include "Shootable.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class Enemy : public GameObject, public Shootable
{
public:
	Enemy(const std::string& objectName, const std::vector<MathPoint>& corners);
	int getHitpoints();
	void action(double timeGain) override;
	bool isInpenetrableBy(GameObject* gameObject) override;
	bool isDamagableBy(GameObject* gameObject) override;

	static constexpr int enemyMaxHealth = 1000;
private:
	void createBullet(const MathPoint& position, int radius, double horizontalSpeed, double verticalSpeed) override;
};

