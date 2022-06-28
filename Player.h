#pragma once
#include "GameObject.h"
#include "MoveableObject.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class Player : public MoveableObject
{
public:
	Player(std::string objectName, const std::vector<Point>& corners);
	bool stoppedVertically(const SDL_Event& event);
	bool stoppedHorizontally(const SDL_Event& event);
	void action(double timeGain) override;
	static constexpr double playerSpeedMultiplier = 2.0;
};

