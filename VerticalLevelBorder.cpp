#include "VerticalLevelBorder.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Camera.h"

VerticalLevelBorder::VerticalLevelBorder(std::string objectName, const MathPoint& position, const std::vector<MathPoint>& corners)
	: GameObject(objectName, position, corners) {}

void VerticalLevelBorder::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), MathPoint(Camera::getObjectPositionOnScreen(position).getX(), Constants::screenHeight / 2));
}

bool VerticalLevelBorder::isInpenetrableBy(GameObject* gameObject)
{
	return true;
}