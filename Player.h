#pragma once
#include "GameObject.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class Player : public GameObject
{
public:
	Player(std::string objectName);
	bool stoppedVertically(const SDL_Event& event);
	bool stoppedHorizontally(const SDL_Event& event);
	void setVerticalSpeed(double verticalSpeed);
	void setHorizontalSpeed(double horizontalSpeed);
	void action(double timeGain) override;
	static constexpr double playerSpeedMultiplier = 2.0;
private:
	void checkHorizontalBorders();
	void checkVerticalBorders();
	double horizontalSpeed, verticalSpeed;
};

