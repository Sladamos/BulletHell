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
	GameObject(const std::string& objectName, const MathPoint& position, int radius);
	GameObject(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners);
	virtual ~GameObject() = default;
	//GameObject(std::string objectName, int numberOfAnimations);	//TODO: add animations
	Shape* getShape();
	MathPoint getPosition();
	virtual void setPosition(const MathPoint& position);
	virtual void action(double timeGain);
	virtual void print(Painter* painter);
	bool isMoveable();
	bool isPlayer();
	bool isEnemy();
	virtual bool shouldBeDestroyed();
	virtual bool isPickableBy(GameObject* gameObject);
	virtual bool isInpenetrableBy(GameObject* gameObject);
protected:
	MathPoint position;
	std::string objectName;
};

