#pragma once
#include <string>
#include "GameObject.h"
#include "Moveable.h"
#include "MathPoint.h"
class Bullet : public GameObject, public Moveable
{
public:
	Bullet(const std::string& objectName, GameObject* owner, const MathPoint& position, int damageDealt, double horizontalSpeed, double verticalSpeed);
	Bullet(const std::string& objectName, GameObject* owner, const MathPoint& position, int damageDealt, int radius, double horizontalSpeed, double verticalSpeed);
	Bullet(const std::string& objectName, GameObject* owner, const MathPoint& position, double horizontalSpeed, double verticalSpeed);
	GameObject* getOwner();
	void action(double timeGain) override;
	void repairMove(GameObject* collidableObject, double timeGain) override;
	void undoVerticalMove(double timeGain) override {};
	void undoHorizontalMove(double timeGain) override {};
	virtual void hit(GameObject* targetObject);
	bool shouldBeDestroyed() override;

	static double constexpr speedMultiplier = 3;
	constexpr static int maxRange = 400;
protected:
	bool toDestroy;
private:
	void changeScoreIfNecessary(GameObject* targetObject);
	bool isOutOfRange();

	constexpr static int defaultDamage = 10;
	int damageDealt;
	MathPoint launchPosition;
	GameObject* owner;
};