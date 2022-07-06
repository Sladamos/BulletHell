#pragma once
#include "ShootingTimer.h"
class Shootable
{
public:
	Shootable(double shootingTimeLimit);	//TODO basic bullet name in constructor
	virtual ~Shootable();
	void randomShooting();
	//TODO: jak dodawaæ nowe bullety do levela -> level statyczne metody?
protected:
	void shootIfPossible(void(Shootable::*shootingPattern)());
private:
	ShootingTimer* shootingTimer;
};

