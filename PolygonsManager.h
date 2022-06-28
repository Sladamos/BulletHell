#pragma once
#include <map>
#include <string>
#include <vector>
#include "Polygon.h"
class PolygonsManager
{
public:
	static void addPolygon(const std::string& objectName, Polygon* polygon);
	static Polygon* getPolygon(const std::string& objectName);
	static void freePolygons();
private:
	static std::map<std::string, Polygon*> polygons;
};

