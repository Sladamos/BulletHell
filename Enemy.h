#pragma once
#include "GameObject.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class Enemy : public GameObject
{
public:
	Enemy(std::string objectName, const std::vector<MathPoint>& corners);
	int getHitpoints();
	void action(double timeGain) override;
	bool isInpenetrableBy(GameObject* gameObject) override;

	static constexpr int enemyMaxHealth = 1000;
protected:
	int hitpoints;
};

