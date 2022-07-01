#include "LevelPainter.h"
#include "TimeManager.h"
#include "Level.h"
#include "Camera.h"

LevelPainter::LevelPainter(Level* level, SDL_Window* window, SDL_Renderer* renderer) : Painter(window, renderer), level(level)
{
	addFpsTimer();
	background = SDL_LoadBMP("./gfx/background.bmp");
}

void LevelPainter::addFpsTimer()
{
	fpsTimer = new FpsTimer(0.5);
	TimeManager::addTimer(fpsTimer);
}

void LevelPainter::drawScreen()
{
	SDL_FillRect(screen, NULL, blackColor);
	drawBackground();
	printGameObjects();
	drawStatistics();
	drawWalls();
	updateTextureAndRenderer();
	fpsTimer->incrementFrames();
}

void LevelPainter::drawBackground()
{
	drawObject(background, Point((Constants::screenWidth - Constants::statsWidth) / 2, Constants::screenHeight / 2));
}

void LevelPainter::drawWalls()
{
	if (Camera::isPlayerNearTheTopBorder())
		drawTopWall();
	else if (Camera::isPlayerNearTheBottomBorder())
		drawBottomWall();

	if (Camera::isPlayerNearTheRightBorder())
		drawRightWall();
	else if (Camera::isPlayerNearTheLeftBorder())
		drawLeftWall();
}

void LevelPainter::drawTopWall()
{
	drawFillRectangle(Point(), Constants::screenWidth - Constants::statsWidth, Constants::wallSize, blueColor);
}

void LevelPainter::drawRightWall()
{
	drawFillRectangle(Point(Constants::screenWidth - Constants::statsWidth - Constants::wallSize, 0), Constants::wallSize, Constants::screenHeight, blueColor);
}

void LevelPainter::drawBottomWall()
{
	drawFillRectangle(Point(0, Constants::screenHeight - Constants::wallSize), Constants::screenWidth - Constants::statsWidth, Constants::wallSize, blueColor);
}

void LevelPainter::drawLeftWall()
{
	drawFillRectangle(Point(), Constants::wallSize, Constants::screenHeight, blueColor);
}

void LevelPainter::printGameObjects()
{
	for (GameObject* gameObject : level->getGameObjects())
		if(Camera::isObjectInRange(gameObject))
			gameObject->print(this);
}

void LevelPainter::drawStatistics()
{
	drawStatisticsPanel();
	drawHealthBars();
	Point textCoords(Constants::screenWidth - Constants::statsWidth + 15, 20 + playerHpBarHeight + 2 * playerHpBarFrameSize);
	sprintf(text, "Time = %.1lf s ", level->getLevelTimer()->getTimerValue());
	drawString(textCoords);
	sprintf(text, "%.0lf FPS", fpsTimer->getFps());
	drawString(textCoords.moveByVector(0, 2 * Constants::smallLetterSize));
	sprintf(text, "x = %d y = %d", level->getPlayer()->getPosition().getX(), level->getPlayer()->getPosition().getY());
	drawString(textCoords.moveByVector(0, 2 * Constants::smallLetterSize));
	sprintf(text, "Contolos:");
	drawString(textCoords.moveByVector(0, 2 * Constants::smallLetterSize));
	sprintf(text, "New Game - N");
	drawString(textCoords.moveByVector(0, 2 * Constants::smallLetterSize));
	sprintf(text, "UP - \030, DOWN - \031");
	drawString(textCoords.moveByVector(0, 2 * Constants::smallLetterSize));
	sprintf(text, "LEFT - \032, RIGHT - \033");
	drawString(textCoords.moveByVector(0, 2 * Constants::smallLetterSize));
	//TODO: draw score
}

void LevelPainter::drawStatisticsPanel()
{
	drawFillRectangle(Point(Constants::screenWidth - Constants::statsWidth, 0), Constants::statsWidth, Constants::screenHeight, redColor);
}

void LevelPainter::drawHealthBars()
{
	if (bothSidesOfConflictAreAlive())
	{
		drawPlayerHealthBar();
		drawEnemyHealthBar();
	}
}

bool LevelPainter::bothSidesOfConflictAreAlive()
{
	return level->getEnemy()->getHitpoints() >= 0 && level->getPlayer()->getHitpoints() >= 0;
}

void LevelPainter::drawPlayerHealthBar()
{
	int playerHitpoints = level->getPlayer()->getHitpoints();
	Point barPosition(Constants::screenWidth - Constants::statsWidth * 7 / 8 - playerHpBarFrameSize, 15 - playerHpBarFrameSize);
	double maxRedBarWidth = Constants::statsWidth * 3 / 4;

	drawFillRectangle(barPosition, maxRedBarWidth + 2 * playerHpBarFrameSize, playerHpBarHeight + 2 * playerHpBarFrameSize, blackColor);
	drawFillRectangle(barPosition.moveByVector(playerHpBarFrameSize, playerHpBarFrameSize), maxRedBarWidth * playerHitpoints / Player::playerMaxHealth,
		playerHpBarHeight, redColor);
	sprintf(text, "HP: %d / %d", playerHitpoints, Player::playerMaxHealth);
	drawString(barPosition.moveByVector((maxRedBarWidth - strlen(text) * Constants::smallLetterSize) / 2, playerHpBarHeight / 2));
}

void LevelPainter::drawEnemyHealthBar()
{
	int barSize = 10;
	double partOfLostHp = (static_cast<double>(level->getEnemy()->getHitpoints()) / Enemy::enemyMaxHealth);
	drawFillRectangle(Point(barSize, (1 - partOfLostHp) * (Constants::screenHeight - 2 * barSize)), barSize,
		partOfLostHp * (Constants::screenHeight - barSize), redColor);
}

LevelPainter::~LevelPainter()
{
	delete fpsTimer;
	SDL_FreeSurface(background);
}