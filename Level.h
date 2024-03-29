#pragma once
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "InterfaceElement.h"
class Bullet;
class LevelEngine;
class Level : public InterfaceElement
{
public:
	Level(SDL_Window* window, SDL_Renderer* renderer);
	~Level();
	Timer* getLevelTimer();
	Player* getPlayer();
	std::list<Enemy*>& getEnemies();
	std::list<GameObject*>& getGameObjects();
	std::list<GameObject*>& getGameObjectsWithoutBullets();
	void start() override;
	void destroyGameObject(GameObject* gameObject);
	static void addGameObject(GameObject* newObject);
	bool areAllEnemiesDead();

	static constexpr int width = (3 * Game::screenWidth / 4 * 2);
	static constexpr int height = Game::screenHeight * 2;
protected:
	void addEnemy(Enemy* enemy);
private:
	void createGameObjects();
	void createLevelBorders();
	virtual void createEnemies() = 0;
	std::list<GameObject*> extractGameObjectsWithoutBullets();

	Timer* levelTimer;
	LevelEngine* levelEngine;
	std::list<GameObject*> objectsWithoutBullets;
	std::list<Enemy*> enemies;
	static std::list<GameObject*> gameObjects;
};


