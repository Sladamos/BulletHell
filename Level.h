#pragma once
#include "TimeManager.h"
#include "Painter.h"
#include "Player.h"
#include "Enemy.h"
#include "LevelResult.h"
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
protected:
	std::list<GameObject*> gameObjects;
private:
	void handleLevelEvents();
	void createGameObjects();
	void performGameObjectsActions(double timeGain);
	void handlePlayerMovement(const SDL_Event& event);
	virtual void createEnemy() = 0;
	//TODO: createBullets() - pure virtual
	bool isLevelInProgress();
	bool isPlayer(GameObject* object);
	bool isEnemy(GameObject* object);

	LevelResult levelResult;
	Timer* levelTimer;
	Painter* levelPainter;
	TimeManager* timeManager;
};


