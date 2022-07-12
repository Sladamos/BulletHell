#pragma once
#include "GameObject.h"
class LevelBorder : public GameObject
{
public:
	LevelBorder(std::string objectName, const MathPoint& position, const std::vector<MathPoint>& corners);
	bool isInpenetrableBy(GameObject* gameObject) override;

	static constexpr int borderSize = 10;
};

