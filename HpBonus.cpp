#include "HpBonus.h"
#include "MathPoint.h"

HpBonus::HpBonus(const std::string& objectName, const std::vector<MathPoint>& corners, int healValue) : 
		GameObject(objectName, MathPoint(300,300), corners), healValue(healValue), toDestroy(false) {}

HpBonus::HpBonus(const std::string& objectName, const std::vector<MathPoint>& corners) :
	HpBonus(objectName, corners, defaultHealValue) {}

bool HpBonus::isPickableBy(GameObject* gameObject)
{
	if (gameObject->isPlayer())
		return true;
	return false;	
}

void HpBonus::affectOn(GameObject* changedObject)
{
	changedObject->incraseHitpoints(healValue);
	toDestroy = true;
}

bool HpBonus::shouldBeDestroyed()
{
	return toDestroy;
}