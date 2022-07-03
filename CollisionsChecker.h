#pragma once
#include <list>
#include "MathPoint.h"
class GameObject;
class Circle;
class Polygon;
class CollisionsChecker
{
public:
	static void checkCollisions(GameObject*& checkedObject, const std::list<GameObject*>& gameObjectsWithoutBullets, double timeGain);
private:
	static bool occursCollisionBetweenObjects(GameObject*& checkedObject, GameObject*& collidableObject);
	static bool collisionOccurs(Circle* checkedCircle, Circle* collidableCircle, const MathPoint& checkedPosition, const MathPoint& collidablePosition);
	static bool collisionOccurs(Circle* checkedCircle, Polygon* collidablePolygon, const MathPoint& checkedPosition, const MathPoint& collidablePosition);
	static bool collisionOccurs(Polygon* checkedPolygon, Circle* collidableCircle, const MathPoint& checkedPosition, const MathPoint& collidablePosition);
	static bool collisionOccurs(Polygon* checkedPolygon, Polygon* collidablePolygon, const MathPoint& checkedPosition, const MathPoint& collidablePosition);
};

