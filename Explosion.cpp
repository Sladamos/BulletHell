#include "Explosion.h"
#include "BmpManager.h"
#include "Camera.h"
#include "Painter.h"

Explosion::Explosion(const MathPoint& position) : GameObject("./gfx/explosion", position, 60, numberOfFrames), latestFrame(0)
{
	animationTimer = new AnimationTimer(0.1 * numberOfFrames, numberOfFrames);
}

void Explosion::print(Painter* painter)
{
	painter->drawObject(BmpManager::getAnimation(objectName, animationTimer->getCurrentFrameNumber()), Camera::getObjectPositionOnScreen(position));
}
void Explosion::action(double timeGain)
{
	latestFrame = latestFrame > animationTimer->getCurrentFrameNumber() ? latestFrame : animationTimer->getCurrentFrameNumber();
}

bool Explosion::shouldBeDestroyed()
{
	return animationTimer->getCurrentFrameNumber() < latestFrame;
}

Explosion::~Explosion()
{
	delete animationTimer;
}
