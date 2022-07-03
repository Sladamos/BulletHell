#pragma once
#include <list>
#include <string>
#include <vector>
#include "MathPoint.h"
#include "Constants.h"
#include "Shape.h"
class Painter;
class GameObject
{
public:
	GameObject(std::string objectName, const MathPoint& position, int radius);
	GameObject(std::string objectName, const MathPoint& position, const std::vector<MathPoint>& corners);
	//GameObject(std::string objectName, int numberOfAnimations);	//TODO: add animations
	Shape* getShape();
	virtual void checkLevelBorderCollision();
	virtual void action(double timeGain);
	virtual void print(Painter* painter);
	bool isMoveable();
	bool isPlayer();
	bool isEnemy();
	virtual bool isPickableBy(GameObject* gameObject);
	virtual bool isInpenetrableBy(GameObject* gameObject);
	MathPoint getPosition();
protected:
	MathPoint position;
	std::string objectName;
private:
	bool isTryingToCrossTopBorder(Shape* objectShape);
	bool isTryingToCrossRightBorder(Shape* objectShape);
	bool isTryingToCrossBottomBorder(Shape* objectShape);
	bool isTryingToCrossLeftBorder(Shape* objectShape);
};

