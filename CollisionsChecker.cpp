#include "CollisionsChecker.h"
#include "GameObject.h"
#include "Moveable.h"
#include "Circle.h"
#include "Polygon.h"
#include "MathVector.h"
#include "MathStretch.h"

void CollisionsChecker::checkCollisions(GameObject*& checkedObject, const std::list<GameObject*>& gameObjectsWithoutBullets, double timeGain)
{
	for (GameObject* collidableObject : gameObjectsWithoutBullets)
	{
		if (checkedObject != collidableObject  && checkedObject->isMoveable() && occursCollisionBetweenObjects(checkedObject, collidableObject))
			if (collidableObject->isInpenetrableBy(checkedObject))
				repairObjectMove(checkedObject, collidableObject, timeGain);
	}
}

bool CollisionsChecker::occursCollisionBetweenObjects(GameObject*& checkedObject, GameObject*& collidableObject)
{
	Shape *checkedShape = checkedObject->getShape(), *collidableShape = collidableObject->getShape();
	if (checkedShape->isPolygon())
	{
		if(collidableShape->isCircle())
			return occursCollisionBetweenShapes(dynamic_cast<Polygon*>(checkedShape), dynamic_cast<Circle*>(collidableShape), checkedObject->getPosition(), collidableObject->getPosition());
		else
			return occursCollisionBetweenShapes(dynamic_cast<Polygon*>(checkedShape), dynamic_cast<Polygon*>(collidableShape), checkedObject->getPosition(), collidableObject->getPosition());
	}
	else
	{
		if (collidableShape->isCircle())
			return occursCollisionBetweenShapes(dynamic_cast<Circle*>(checkedShape), dynamic_cast<Circle*>(collidableShape), checkedObject->getPosition(), collidableObject->getPosition());
		else
			return occursCollisionBetweenShapes(dynamic_cast<Circle*>(checkedShape), dynamic_cast<Polygon*>(collidableShape), checkedObject->getPosition(), collidableObject->getPosition());
	}
}

bool CollisionsChecker::occursCollisionBetweenShapes(Circle* checkedCircle, Circle* collidableCircle, const MathPoint& checkedPosition, const MathPoint& collidablePosition)
{
	return MathVector(checkedPosition, collidablePosition).getLength() <= checkedCircle->getRadius() + collidableCircle->getRadius();
}

bool CollisionsChecker::occursCollisionBetweenShapes(Circle* checkedCircle, Polygon* collidablePolygon, const MathPoint& checkedPosition, const MathPoint& collidablePosition)
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

bool CollisionsChecker::occursCollisionBetweenShapes(Polygon* checkedPolygon, Circle* collidableCircle, const MathPoint& checkedPosition, const MathPoint& collidablePosition)
{
	return occursCollisionBetweenShapes(collidableCircle, checkedPolygon, collidablePosition, checkedPosition);
}	

bool CollisionsChecker::occursCollisionBetweenShapes(Polygon* checkedPolygon, Polygon* collidablePolygon, const MathPoint& checkedPosition, const MathPoint& collidablePosition)
{
	std::vector<MathPoint> collidableCorners = collidablePolygon->getCorners();
	updateCollidableCornersCenter(collidableCorners, checkedPosition, collidablePosition);
	return doesStretchesIntersectionExists(checkedPolygon->getCorners(), collidableCorners);
}

bool CollisionsChecker::doesStretchesIntersectionExists(const std::vector<MathPoint>& checkedStretchesCorners, const std::vector<MathPoint>& collidableStretchesCorners)
{
	MathPoint previousCheckedCorner = checkedStretchesCorners.back();
	for (MathPoint checkedCorner : checkedStretchesCorners)
	{
		if (MathStretch(checkedCorner, previousCheckedCorner).intersetsWithAnyStretch(collidableStretchesCorners))
			return true;
		previousCheckedCorner = checkedCorner;
	}
	return false;
}

void CollisionsChecker::updateCollidableCornersCenter(std::vector<MathPoint>& collidableCorners, const MathPoint& newCenter, const MathPoint& previousCenter)
{
	for (MathPoint& collidableCorner : collidableCorners)
		collidableCorner.changeCoordinatesCenter(newCenter, previousCenter);
}

void CollisionsChecker::repairObjectMove(GameObject*& repairingObject, GameObject*& collidableObject, double timeGain)
{
	MathPoint incorretPosition = repairingObject->getPosition();
	dynamic_cast<Moveable*>(repairingObject)->undoHorizontalMove(timeGain);
	if (occursCollisionBetweenObjects(repairingObject, collidableObject))
	{
		repairingObject->setPosition(incorretPosition);
		dynamic_cast<Moveable*>(repairingObject)->undoVerticalMove(timeGain);
	}
}