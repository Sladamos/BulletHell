#pragma once
#include <list>
#include <vector>
#include "MathPoint.h"
class GameObject;
class Circle;
class Polygon;
class CollisionsChecker
{
public:
	static bool occursCollisionBetweenObjects(GameObject* checkedObject, GameObject* collidableObject);
private:
	static bool occursCollisionBetweenShapes(Circle* checkedCircle, Circle* collidableCircle, const MathPoint& checkedPosition, const MathPoint& collidablePosition);
	static bool occursCollisionBetweenShapes(Circle* checkedCircle, Polygon* collidablePolygon, const MathPoint& checkedPosition, const MathPoint& collidablePosition);
	static bool occursCollisionBetweenShapes(Polygon* checkedPolygon, Circle* collidableCircle, const MathPoint& checkedPosition, const MathPoint& collidablePosition);
	static bool occursCollisionBetweenShapes(Polygon* checkedPolygon, Polygon* collidablePolygon, const MathPoint& checkedPosition, const MathPoint& collidablePosition);
	static bool doesStretchesIntersectionExists(const std::vector<MathPoint>& checkedStretchesCorners, const std::vector<MathPoint>& collidableStretchesCorners);
	static void updateCollidableCornersCenter(std::vector<MathPoint>& collidableCorners, const MathPoint& newCenter, const MathPoint& previousCenter);
};

