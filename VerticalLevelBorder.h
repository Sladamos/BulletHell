#include "LevelBorder.h"
#pragma once
class Painter;
class VerticalLevelBorder : public LevelBorder
{
public:
	VerticalLevelBorder(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners);
	virtual void print(Painter* painter);
};

