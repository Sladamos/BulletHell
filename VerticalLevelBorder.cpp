#include "VerticalLevelBorder.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Camera.h"

VerticalLevelBorder::VerticalLevelBorder(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners)
	: LevelBorder(objectName, position, corners) {}

void VerticalLevelBorder::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), MathPoint(Camera::getObjectPositionOnScreen(position).getX(), Game::screenHeight / 2));
}
