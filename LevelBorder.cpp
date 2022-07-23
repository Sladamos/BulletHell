#include "LevelBorder.h"

LevelBorder::LevelBorder(std::string objectName, const MathPoint& position, const std::vector<MathPoint>& corners)
	: GameObject(objectName, position, corners) {}

bool LevelBorder::isInpenetrableBy(GameObject* gameObject)
{
	return true;
}