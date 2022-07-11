#pragma once
#include "GameObject.h"
#include "Moveable.h"
#include "Shootable.h"
#include "InvicibilityTimer.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class Player : public GameObject, public Moveable, public Shootable
{
public:
	Player(const std::string& objectName, const std::vector<MathPoint>& corners);
	~Player();
	bool stoppedVertically(const SDL_Event& event);
	bool stoppedHorizontally(const SDL_Event& event);
	bool isInpenetrableBy(GameObject* gameObject) override;
	bool isDamagableBy(GameObject* gameObject) override;
	void setShootingPermission(bool fireButtonIsPressed);
	void action(double timeGain) override;
	void print(Painter* painter) override;
	void setPosition(const MathPoint& position) override;
	void undoHorizontalMove(double timeGain) override;
	void undoVerticalMove(double timeGain) override;
	void updateViewingAngle();
	void decreaseHitpoints(int damageDealt) override;
	bool shouldBeDestroyed() override;

	static constexpr double playerSpeedMultiplier = 1.5;
private:
	void createBullet(const MathPoint& position, double horizontalSpeed, double verticalSpeed) override;

	InvicibilityTimer* invicibilityTimer;
	const std::string invicibilityFrame = "./gfx/invicibilityFrame";
	bool fireButtonIsPressed;
	static constexpr int playerMaxHealth = 100;
};

