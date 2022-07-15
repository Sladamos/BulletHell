#include <vector>
#include <algorithm>
#include <iterator>
#include "MathPoint.h"
#include "Level.h"
#include "BmpManager.h"
#include "ShapesManager.h"
#include "VerticalLevelBorder.h"
#include "HorizontalLevelBorder.h"
#include "Bullet.h"
#include "HpBonus.h"
#include "LevelEngine.h"
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"

std::list<GameObject*> Level::gameObjects = std::list<GameObject*>();

Level::Level(SDL_Window* window, SDL_Renderer* renderer) : result(LevelResult::unknown), levelTimer(new Timer()), 
			levelEngine(new LevelEngine(this, window, renderer)) {}

Player* Level::getPlayer()
{
	for (GameObject* object : gameObjects)
	{
		if (object->isPlayer())
			return dynamic_cast<Player*>(object);
	}
	return nullptr;
}

std::list<Enemy*>& Level::getEnemies()
{
	return enemies;
}

LevelResult Level::getResult()
{
	return result;
}

std::list<GameObject*>& Level::getGameObjectsWithoutBullets()
{
	return objectsWithoutBullets;
}

void Level::setResult(LevelResult result)
{
	this->result = result;
}

void Level::addGameObject(GameObject* newObject)
{
	gameObjects.push_back(newObject);
}

void Level::addEnemy(Enemy* enemy)
{
	gameObjects.push_back(enemy);
	enemies.push_back(enemy);
}

void Level::createGameObjects()
{
	gameObjects.push_back(new Player("./gfx/player_an_1", std::vector<MathPoint>{MathPoint(-40, -40), MathPoint(-40, 40), MathPoint(40, 40), MathPoint(40, -40)}));
	createEnemies();
	createLevelBorders();
	gameObjects.push_back(new HpBonus("./gfx/hpBonus", MathPoint(300, 300), std::vector<MathPoint>{MathPoint(-16, -4), MathPoint(-8, -16), MathPoint(8, -16), MathPoint(16, -4), MathPoint(0, 16)}));
	objectsWithoutBullets = extractGameObjectsWithoutBullets();
}

void Level::createLevelBorders()
{
	int wallSize = LevelBorder::borderSize;
	gameObjects.push_back(new HorizontalLevelBorder("./gfx/horizontalBorder", MathPoint(width/2, wallSize/2), std::vector<MathPoint>{MathPoint(-width/2, -wallSize/2), MathPoint(-width/2, wallSize/2), MathPoint(width/2, wallSize/2), MathPoint(width/2, -wallSize/2)}));
	gameObjects.push_back(new VerticalLevelBorder("./gfx/verticalBorder", MathPoint(width-wallSize/2, height/2), std::vector<MathPoint>{MathPoint(-wallSize/2, -height/2), MathPoint(-wallSize/2, height/2), MathPoint(wallSize/2, height/2), MathPoint(wallSize/2, -height/2)}));
	gameObjects.push_back(new HorizontalLevelBorder("./gfx/horizontalBorder", MathPoint(width/2, height - wallSize/2), std::vector<MathPoint>{MathPoint(-width/2, -wallSize/2), MathPoint(-width/2, wallSize/2), MathPoint(width/2, wallSize/2), MathPoint(width/2, -wallSize/2)}));
	gameObjects.push_back(new VerticalLevelBorder("./gfx/verticalBorder", MathPoint(wallSize/2, height/2), std::vector<MathPoint>{MathPoint(-wallSize/2, -height/2), MathPoint(-wallSize/2, height/2), MathPoint(wallSize/2, height/2), MathPoint(wallSize/2, -height/2)}));
}

std::list<GameObject*>& Level::getGameObjects()
{
	return gameObjects;
}

Timer* Level::getLevelTimer()
{
	return levelTimer;
}

void Level::start()
{
	createGameObjects();
	levelEngine->start();
}

void Level::destroyGameObject(GameObject* gameObject)
{
	if (!gameObject->isBullet())
		objectsWithoutBullets.remove(gameObject);
	gameObjects.remove(gameObject);
	delete gameObject;
}

std::list<GameObject*> Level::extractGameObjectsWithoutBullets()
{
	std::list<GameObject*> objectsWithoutBullets;
	std::copy_if(gameObjects.begin(), gameObjects.end(), std::back_inserter(objectsWithoutBullets),
		[](GameObject* object) {return dynamic_cast<Bullet*>(object) == nullptr; });
	return objectsWithoutBullets;
}

bool Level::areAllEnemiesDead()
{
	bool enemiesLose = true;
	for (Enemy* enemy : enemies)
	{
		if (enemy->getHitpoints() > 0)
			enemiesLose = false;
	}
	return enemiesLose;
}

Level::~Level()
{
	for (GameObject* object : gameObjects)
		delete object;
	gameObjects.clear();
	BmpManager::freeBitmaps();
	ShapesManager::freeShapes();
	delete levelTimer;
	delete levelEngine;
}