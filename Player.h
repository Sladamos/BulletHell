#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player(std::string objectName);
	void setSpeed(double speed);
	void action(double timeGain) override;
private:
	double distance;
	double speed;
};

