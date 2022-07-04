#include "CollisionsChecker.h"
#include <math.h>
#include "GameObject.h"
#include "Moveable.h"
#include "Circle.h"
#include "Polygon.h"
#include "MathVector.h"
#include "MathStretch.h"

void CollisionsChecker::checkCollisions(GameObject*& checkedObject, const std::list<GameObject*>& gameObjectsWithoutBullets, double timeGain)
{
	for (GameObject* gameObject : gameObjectsWithoutBullets)
	{
		if (gameObject != checkedObject && checkedObject->isMoveable())
		{
			if (gameObject->isInpenetrableBy(checkedObject) && occursCollisionBetweenObjects(checkedObject, gameObject))
				dynamic_cast<Moveable*>(checkedObject)->undoMove(timeGain);
		}
	}
}

bool CollisionsChecker::occursCollisionBetweenObjects(GameObject*& checkedObject, GameObject*& collidableObject)
{
	Shape *checkedShape = checkedObject->getShape(), *collidableShape = collidableObject->getShape();
	if (checkedShape->isPolygon())
	{
		if(collidableShape->isCircle())
			return collisionOccurs(dynamic_cast<Polygon*>(checkedShape), dynamic_cast<Circle*>(collidableShape), checkedObject->getPosition(), collidableObject->getPosition());
		else
			return collisionOccurs(dynamic_cast<Polygon*>(checkedShape), dynamic_cast<Polygon*>(collidableShape), checkedObject->getPosition(), collidableObject->getPosition());
	}
	else
	{
		if (collidableShape->isCircle())
			return collisionOccurs(dynamic_cast<Circle*>(checkedShape), dynamic_cast<Circle*>(collidableShape), checkedObject->getPosition(), collidableObject->getPosition());
		else
			return collisionOccurs(dynamic_cast<Circle*>(checkedShape), dynamic_cast<Polygon*>(collidableShape), checkedObject->getPosition(), collidableObject->getPosition());
	}
}

bool CollisionsChecker::collisionOccurs(Circle* checkedCircle, Circle* collidableCircle, const MathPoint& checkedPosition, const MathPoint& collidablePosition)
{
	return MathVector(checkedPosition, collidablePosition).getLength() <= checkedCircle->getRadius() + collidableCircle->getRadius();
}

bool CollisionsChecker::collisionOccurs(Circle* checkedCircle, Polygon* collidablePolygon, const MathPoint& checkedPosition, const MathPoint& collidablePosition)
{
	std::vector<MathPoint> corners = collidablePolygon->getCorners();
	MathPoint circleCenter(checkedPosition, collidablePosition), secondBaseCorner = corners.back();
	for (MathPoint firstBaseCorner : corners)
	{
		if (MathStretch(firstBaseCorner, secondBaseCorner).isCircleTangent(circleCenter, checkedCircle->getRadius())
			|| MathVector(firstBaseCorner, circleCenter).getLength() <= checkedCircle->getRadius())
			return true;
		secondBaseCorner = firstBaseCorner;
	}
	return false;
}

bool CollisionsChecker::collisionOccurs(Polygon* checkedPolygon, Circle* collidableCircle, const MathPoint& checkedPosition, const MathPoint& collidablePosition)
{
	return collisionOccurs(collidableCircle, checkedPolygon, collidablePosition, checkedPosition);
}

bool CollisionsChecker::collisionOccurs(Polygon* checkedPolygon, Polygon* collidablePolygon, const MathPoint& checkedPosition, const MathPoint& collidablePosition)
{	//TODO ULTRA STYLE && UNDOMOVE
	std::vector<MathPoint> checkedCorners = checkedPolygon->getCorners(), collidableCorners = collidablePolygon->getCorners();
	MathPoint previousCheckedCorner = checkedCorners.back();

	//updateCollidableCornersCenter();	//TODO funckaj 1
	for (MathPoint& collidableCorner : collidableCorners)
		collidableCorner.changeCoordinatesCenter(checkedPosition, collidablePosition);

	for (MathPoint checkedCorner : checkedCorners)	//TODO funkcja 2
	{
		MathPoint previousCollidableCorner = collidableCorners.back();
		for (MathPoint collidableCorner : collidableCorners)	//TODO funckaj 3
		{
			if (MathStretch(checkedCorner, previousCheckedCorner).intersets(MathStretch(collidableCorner, previousCollidableCorner)))
				return true;
			previousCollidableCorner = collidableCorner;
		}
		previousCheckedCorner = checkedCorner;
	}

	return false;	//TODO do funkcji 2
}