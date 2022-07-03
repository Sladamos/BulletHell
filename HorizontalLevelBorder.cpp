#include "HorizontalLevelBorder.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Camera.h"

HorizontalLevelBorder::HorizontalLevelBorder(std::string objectName, const MathPoint& position, const std::vector<MathPoint>& corners)
	: GameObject(objectName, position, corners) {}

void HorizontalLevelBorder::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), MathPoint((Constants::screenWidth - Constants::statsWidth) / 2, Camera::getObjectPositionOnScreen(position).getY()));
}

bool HorizontalLevelBorder::isInpenetrableBy(GameObject* gameObject)
{
	return true;
}