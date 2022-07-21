#include <algorithm>
#include <iterator>
#include "LevelEngine.h"
#include "Level.h"

LevelEngine::LevelEngine(Level* currentLevel, SDL_Window* window, SDL_Renderer* renderer) :
	currentLevel(currentLevel), levelPainter(new LevelPainter(currentLevel, window, renderer)), timeManager(new TimeManager()) {}

void LevelEngine::start()
{
	timeManager->startCounting();
	while (currentLevel->isGameCommandUndefined())
	{
		levelPainter->drawScreen();
		timeManager->increaseAndExecuteTimers();
		handleLevelEvents();
		performGameObjectsActions(timeManager->getTimeGain());
		actualizeGameCommand();
	}
}

void LevelEngine::handleLevelEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
	{
		switch (event.type) 
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP: case SDLK_LEFT: case SDLK_DOWN: case SDLK_RIGHT:
				handlePlayerMovement(event);
				break;
			case SDLK_f:
				currentLevel->getPlayer()->setShootingPermission(true);
				break;
			case SDLK_ESCAPE:
				currentLevel->setGameCommand(GameCommand::backToMenu);
				break;
			case SDLK_n:
				currentLevel->setGameCommand(GameCommand::restartLevel);
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP: case SDLK_LEFT: case SDLK_DOWN: case SDLK_RIGHT:
				handlePlayerMovement(event);
				break;
			case SDLK_f:
				currentLevel->getPlayer()->setShootingPermission(false);
			}
			break;
		case SDL_QUIT:
			currentLevel->setGameCommand(GameCommand::exitGame);
		};
	}
}

void LevelEngine::handlePlayerMovement(const SDL_Event& event)
{
	Player* player = currentLevel->getPlayer();
	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			player->setVerticalSpeed(-Player::playerSpeedMultiplier);
			break;
		case SDLK_LEFT:
			player->setHorizontalSpeed(-Player::playerSpeedMultiplier);
			break;
		case SDLK_DOWN:
			player->setVerticalSpeed(Player::playerSpeedMultiplier);
			break;
		case SDLK_RIGHT:
			player->setHorizontalSpeed(Player::playerSpeedMultiplier);
		}
		break;
	case SDL_KEYUP:
		if (player->stoppedVertically(event))
			player->setVerticalSpeed(0.0);
		if (player->stoppedHorizontally(event))
			player->setHorizontalSpeed(0.0);
	}
	player->updateViewingAngle();
}

void LevelEngine::performGameObjectsActions(double timeGain)
{
	std::list<GameObject*>& gameObjects = currentLevel->getGameObjects(), &objectsWithoutBullets = currentLevel->getGameObjectsWithoutBullets();
	for (auto it = gameObjects.begin(); it != gameObjects.end();)
	{
		GameObject* object = *it++;
		if (object->shouldBeDestroyed() && !object->isEnemy())
			currentLevel->destroyGameObject(object);
		else if (!object->shouldBeDestroyed())
		{
			object->action(timeGain);
			object->checkCollisions(objectsWithoutBullets, timeGain);
		}
	}
}

void LevelEngine::actualizeGameCommand()
{
	if (currentLevel->getPlayer()->getHitpoints() <= 0)
		currentLevel->setGameCommand(GameCommand::defeat);
	else if (currentLevel->areAllEnemiesDead())
		currentLevel->setGameCommand(GameCommand::victory);
}

LevelEngine::~LevelEngine()
{
	delete levelPainter;
	delete timeManager;
}