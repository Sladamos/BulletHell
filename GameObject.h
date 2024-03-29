#pragma once
#include <list>
#include <string>
#include <vector>
#include "MathPoint.h"
#include "Shape.h"
class Painter;
class GameObject
{
public:
	GameObject(const std::string& objectName, const MathPoint& position, int radius);
	GameObject(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners);
	GameObject(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners, int hitpoints);
	virtual ~GameObject() = default;
	GameObject(const std::string& objectName, const MathPoint& position, int radius, int numberOfAnimations);
	GameObject(const std::string& objectName, const MathPoint& position, const std::vector<MathPoint>& corners, int hitpoints, int numberOfAnimations);
	Shape* getShape();
	MathPoint getPosition();
	int getHitpoints();
	int getMaxHitpoints();
	void checkCollisions(const std::list<GameObject*>& gameObjectsWithoutBullets, double timeGain);
	void increaseHitpoints(int healValue);
	bool isMoveable();
	bool isPlayer();
	bool isEnemy();
	bool isBullet();
	bool isUnholyBullet();
	bool isHolyBullet();
	virtual void decreaseHitpoints(int damageDealt);
	virtual void setPosition(const MathPoint& position);
	virtual void action(double timeGain);
	virtual void print(Painter* painter);
	virtual bool shouldBeDestroyed();
	virtual bool isPickableBy(GameObject* gameObject);
	virtual bool doesGetDamagedBy(GameObject* gameObject);
	virtual bool isInpenetrableBy(GameObject* gameObject);
protected:
	MathPoint position;
	std::string objectName;
	int hitpoints;
	int maxHealth;
};

