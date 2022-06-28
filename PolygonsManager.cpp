#include "PolygonsManager.h"
using namespace std;

map<string, Polygon*> PolygonsManager::polygons = map<string, Polygon*>();

void PolygonsManager::addPolygon(const string& objectName, Polygon* polygon)
{
	if (polygons.find(objectName) == polygons.end())
		polygons.insert(pair <string, Polygon*>(objectName, polygon));
}

void PolygonsManager::freePolygons()
{
	for (auto polygon : polygons)
		delete polygon.second;
	polygons.clear();
}

Polygon* PolygonsManager::getPolygon(const string& objectName)
{
	return polygons.find(objectName)->second;
}
