#include "LevelBorder.h"
#pragma once
class Painter;
class HorizontalLevelBorder: public LevelBorder
{
public:
	HorizontalLevelBorder(const MathPoint& position, const std::vector<MathPoint>& corners);
	virtual void print(Painter* painter);
};

