#include "GameObject.h"
#pragma once
class Painter;
class HorizontalLevelBorder: public GameObject
{
public:
	HorizontalLevelBorder(std::string objectName, const MathPoint& position, const std::vector<MathPoint>& corners);
	bool isInpenetrableBy(GameObject* gameObject) override;
	virtual void print(Painter* painter);
};

