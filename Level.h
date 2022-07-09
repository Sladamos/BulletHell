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
	std::list<Enemy*> getEnemies();
	LevelResult getResult();
	std::list<GameObject*> getGameObjects();
	void startLevel();
	static void addBullet(Bullet* newBullet);
protected:
	void addEnemy(Enemy* enemy);
private:
	void handleLevelEvents();
	void handlePlayerMovement(const SDL_Event& event);
	void createGameObjects();
	void createLevelBorders();
	void performGameObjectsActions(double timeGain);
	void destroyGameObject(GameObject* gameObject);
	void actualizeLevelResult();
	virtual void createEnemies() = 0;
	bool isLevelInProgress();
	bool areAllEnemiesDead();
	std::list<GameObject*> getGameObjectsWithoutBullets();

	LevelResult levelResult;
	Timer* levelTimer;
	LevelPainter* levelPainter;
	TimeManager* timeManager;
	static std::list<GameObject*> gameObjects;
	std::list<GameObject*> objectsWithoutBullets;
	std::list<Enemy*> enemies;
};


