#pragma once
#include "Enemy.h"
#include "Moveable.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
//class MoveableEnemy : public Enemy, public Moveable
//{
//public:
//	MoveableEnemy(std::string objectName, const std::vector<MathPoint>& corners);
//	bool stoppedVertically(const SDL_Event& event);
//	bool stoppedHorizontally(const SDL_Event& event);
//	void action(double timeGain) override;
//	void print(Painter* painter) override;
//	static constexpr double enemySpeedMultiplier = 1.25;
//protected:
//	int hitpoints;
//};
//TODO: future implementation
