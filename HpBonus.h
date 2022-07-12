#pragma once
#include <string>
#include <vector>
#include "GameObject.h"
#include "Pickable.h"
#include "MathPoint.h"
class HpBonus : public GameObject, public Pickable
{
public:
	HpBonus(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners, int healValue);
	HpBonus(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners);
	bool isPickableBy(GameObject* gameObject) override;
	void affectOn(GameObject* changedObject) override;
	bool shouldBeDestroyed() override;
private:
	int healValue;
	bool toDestroy;
	static constexpr int defaultHealValue = 50;
};

