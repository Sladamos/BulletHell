#pragma once
#include "LevelBorder.h"
class Painter;
class HorizontalLevelBorder: public LevelBorder
{
public:
	HorizontalLevelBorder(const std::string& objectName,const MathPoint& position, const std::vector<MathPoint>& corners);
	virtual void print(Painter* painter);
};

