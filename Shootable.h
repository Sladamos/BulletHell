#pragma once
#include "ShootingTimer.h"
class Shootable
{
public:
	Shootable(double shootingTimeLimit);
	virtual ~Shootable();
	//TODO: jak dodawaæ nowe bullety do levela -> level statyczne metody?
protected:
	void randomShooting();
	void shootIfPossible(void(Shootable::*shootingPattern)());
private:
	ShootingTimer* shootingTimer;
};

