#include "LevelPainter.h"
#include "TimeManager.h"
#include "Level.h"
#include "Camera.h"
#include "MathVector.h"

LevelPainter::LevelPainter(Level* level, SDL_Window* window, SDL_Renderer* renderer) : Painter(window, renderer), level(level)
{
	fpsTimer = new FpsTimer(0.5);
	background = SDL_LoadBMP("./gfx/background.bmp");
	statisticsPanel = SDL_LoadBMP("./gfx/statisticsPanel.bmp");
}

void LevelPainter::drawScreen()
{
	SDL_FillRect(screen, NULL, blackColor);
	drawBackground();
	printGameObjects();
	drawStatistics();
	updateTextureAndRenderer();
	fpsTimer->incrementFrames();
}

void LevelPainter::drawBackground()
{
	drawObject(background, MathPoint((Game::screenWidth - statsWidth) / 2, Game::screenHeight / 2));
}

void LevelPainter::drawStatisticsPanel()
{
	drawObject(statisticsPanel, MathPoint(Game::screenWidth - statsWidth / 2, Game::screenHeight / 2));
}

void LevelPainter::printGameObjects()
{
	for (GameObject* gameObject : level->getGameObjects())
		if (Camera::isObjectInRange(gameObject))
		{
			gameObject->print(this);
		}
}

void LevelPainter::drawStatistics()
{
	drawEnemiesHealthBars();	//Its important to draw Enemies bars > statistics panel > player health bar
	drawStatisticsPanel();
	drawPlayerHealthBar();
	MathVector mathVector(MathPoint(0, 2 * smallLetterSize));
	MathPoint textCoords(Game::screenWidth - statsWidth + 15, 20 + playerHpBarHeight + 2 * playerHpBarFrameSize);
	sprintf(text, "Time = %.1lf s ", level->getLevelTimer()->getTimerValue());
	drawString(textCoords);
	sprintf(text, "%.0lf FPS", fpsTimer->getFps());
	drawString(textCoords.moveByVector(mathVector));
	sprintf(text, "x = %d y = %d", level->getPlayer()->getPosition().getX(), level->getPlayer()->getPosition().getY());
	drawString(textCoords.moveByVector(mathVector));
	sprintf(text, "Contolos:");
	drawString(textCoords.moveByVector(mathVector));
	sprintf(text, "New Game - N");
	drawString(textCoords.moveByVector(mathVector));
	sprintf(text, "UP - \030, DOWN - \031");
	drawString(textCoords.moveByVector(mathVector));
	sprintf(text, "LEFT - \032, RIGHT - \033");
	drawString(textCoords.moveByVector(mathVector));
}

void LevelPainter::drawPlayerHealthBar()
{
	int playerHp = level->getPlayer()->getHitpoints(), playerMaxHp = level->getPlayer()->getMaxHitpoints();
	MathPoint barPosition(Game::screenWidth - statsWidth * 7 / 8 - playerHpBarFrameSize, 15 - playerHpBarFrameSize);
	double maxRedBarWidth = statsWidth * 3 / 4;

	drawFillRectangle(barPosition, maxRedBarWidth + 2 * playerHpBarFrameSize, playerHpBarHeight + 2 * playerHpBarFrameSize, blackColor);
	drawFillRectangle(barPosition.moveByVector(MathVector(MathPoint(playerHpBarFrameSize, playerHpBarFrameSize))), maxRedBarWidth * playerHp/ playerMaxHp,
		playerHpBarHeight, redColor);
	sprintf(text, "HP: %d / %d", playerHp, playerMaxHp);
	drawString(barPosition.moveByVector(MathVector(MathPoint((maxRedBarWidth - strlen(text) * smallLetterSize) / 2, playerHpBarHeight / 2))));
}

void LevelPainter::drawEnemiesHealthBars()
{
	int barHeight = 15, barWidth = 60;

	for (Enemy* enemy : level->getEnemies())
	{
		double partOfRemainingHp = (static_cast<double>(enemy->getHitpoints()) / enemy->getMaxHitpoints());
		if (Camera::isObjectInRange(enemy))
		{
			MathPoint position = Camera::getObjectPositionOnScreen(enemy->getPosition()).moveByVector(MathVector(MathPoint(-barWidth / 2, enemy->getShape()->getMostBottomCoordinate() + 5)));
			drawFillRectangle(position, partOfRemainingHp * barWidth, barHeight, redColor);
		}
	}
}

LevelPainter::~LevelPainter()
{
	delete fpsTimer;
	SDL_FreeSurface(background);
	SDL_FreeSurface(statisticsPanel);
}