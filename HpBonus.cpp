#include "HpBonus.h"
#include "MathPoint.h"

HpBonus::HpBonus(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners,  int healValue) :
		GameObject(objectName, position, corners), healValue(healValue), toDestroy(false) {}

HpBonus::HpBonus(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners) :
	HpBonus(objectName, position, corners, defaultHealValue) {}

bool HpBonus::isPickableBy(GameObject* gameObject)
{
	if (gameObject->isPlayer())
		return true;
	return false;	
}

void HpBonus::affectOn(GameObject* changedObject)
{
	changedObject->increaseHitpoints(healValue);
	toDestroy = true;
}

bool HpBonus::shouldBeDestroyed()
{
	return toDestroy;
}