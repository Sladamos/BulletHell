#include "VerticalLevelBorder.h"
#include "Painter.h"
#include "BmpManager.h"
#include "Camera.h"

VerticalLevelBorder::VerticalLevelBorder(const MathPoint& position, const std::vector<MathPoint>& corners)
	: LevelBorder("./gfx/VerticalBorder", position, corners) {}

void VerticalLevelBorder::print(Painter* painter)
{
	painter->drawObject(BmpManager::getBitmap(objectName), MathPoint(Camera::getObjectPositionOnScreen(position).getX(), Game::screenHeight / 2));
}
