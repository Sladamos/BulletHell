#pragma once
#include "TimeManager.h"
#include "LevelPainter.h"
#include "Player.h"
#include "Enemy.h"
#include "LevelResult.h"
class Bullet;
class Level
{
public:
	Level(SDL_Window* window, SDL_Renderer* renderer);
	~Level();
	Timer* getLevelTimer();
	Player* getPlayer();
	Enemy* getEnemy();
	LevelResult getResult();
	std::list<GameObject*> getGameObjects();
	void startLevel();
	static void addBullet(Bullet* newBullet);
protected:
	static std::list<GameObject*> gameObjects;
private:
	void handleLevelEvents();
	void createGameObjects();
	void performGameObjectsActions(double timeGain);
	void handlePlayerMovement(const SDL_Event& event);
	virtual void createEnemy() = 0;
	void createLevelBorders();
	bool isLevelInProgress();

	LevelResult levelResult;
	Timer* levelTimer;
	LevelPainter* levelPainter;
	TimeManager* timeManager;
};


