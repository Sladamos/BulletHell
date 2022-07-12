#include "HorizontalLevelBorder.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Camera.h"

HorizontalLevelBorder::HorizontalLevelBorder(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners)
	: LevelBorder(objectName, position, corners) {}

void HorizontalLevelBorder::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), MathPoint((Game::screenWidth - Painter::statsWidth) / 2, Camera::getObjectPositionOnScreen(position).getY()));
}
