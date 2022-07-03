#pragma once
#include "GameObject.h"
#include "Moveable.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class Player : public GameObject, public Moveable
{
public:
	Player(std::string objectName, const std::vector<MathPoint>& corners);
	int getHitpoints();
	bool stoppedVertically(const SDL_Event& event);
	bool stoppedHorizontally(const SDL_Event& event);
	void action(double timeGain) override;
	void print(Painter* painter) override;
	bool isInpenetrableBy(GameObject* gameObject) override;
	virtual void undoMove(double timeGain) override;

	static constexpr double playerSpeedMultiplier = 1.5;
	static constexpr int playerMaxHealth = 100;
private:
	int hitpoints;
};

