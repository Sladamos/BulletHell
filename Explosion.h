#pragma once
#include "GameObject.h"
#include "AnimationTimer.h"
class Explosion : public GameObject
{
public:
	Explosion(const MathPoint& position);
	virtual ~Explosion();
	void print(Painter* painter) override;
	void action(double timeGain) override;
	virtual bool shouldBeDestroyed() override;
private:
	AnimationTimer* animationTimer;
	int latestFrame;
	static constexpr int numberOfFrames = 2;
};

