#include "GameObject.h"
#include "Painter.h"
#include "Level.h"
#include "Camera.h"

Painter::Painter(Level* level, SDL_Window* window, SDL_Renderer* renderer) : level(level), window(window), renderer(renderer)
{
	screen = SDL_CreateRGBSurface(0, Constants::screenWidth, Constants::screenHeight, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, Constants::screenWidth, Constants::screenHeight);
	charset = SDL_LoadBMP("./gfx/cs8x8.bmp");
	background = SDL_LoadBMP("./gfx/background.bmp");
	addFpsTimer();
	setColors();	//TODO: make painter abstract and menu will inherit after painter with new constructor(without fpstimer -> nullptr)
}

void Painter::addFpsTimer()
{
	fpsTimer = new FpsTimer(0.5);
	TimeManager::addTimer(fpsTimer);
}

void Painter::setColors()
{
	blackColor = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	redColor = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	blueColor = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	SDL_SetColorKey(charset, true, 0x000000);
}

void Painter::drawScreen()
{
	SDL_FillRect(screen, NULL, blackColor);
	drawBackground();
	printGameObjects();
	drawStatistics();
	drawWalls();
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
	fpsTimer->incrementFrames();
}

void Painter::drawBackground()
{
	drawObject(background, Point((Constants::screenWidth - Constants::statsWidth) / 2, Constants::screenHeight / 2));
}

void Painter::drawWalls()
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

void Painter::drawTopWall()
{
	drawFillRectangle(Point(), Constants::screenWidth - Constants::statsWidth, Constants::wallSize, blueColor);
}

void Painter::drawRightWall()
{
	drawFillRectangle(Point(Constants::screenWidth-Constants::statsWidth-Constants::wallSize,0), Constants::wallSize, Constants::screenHeight, blueColor);
}

void Painter::drawBottomWall()
{
	drawFillRectangle(Point(0,Constants::screenHeight-Constants::wallSize), Constants::screenWidth - Constants::statsWidth, Constants::wallSize, blueColor);
}

void Painter::drawLeftWall()
{
	drawFillRectangle(Point(), Constants::wallSize, Constants::screenHeight, blueColor);
}

void Painter::printGameObjects()
{
	for (GameObject* gameObject : level->getGameObjects())
		gameObject->print(this);	//TODO if is in camera range print
}

void Painter::drawStatistics()
{
	drawFillRectangle(Point(Constants::screenWidth-Constants::statsWidth, 0), Constants::statsWidth, Constants::screenHeight, redColor);
	drawHealthBars();
	Point textCoords(Constants::screenWidth - Constants::statsWidth + 15, 20 + playerHpBarHeight + 2 * playerHpBarFrameSize);
	sprintf(text, "Time = %.1lf s ", level->getLevelTimer()->getTimerValue());
	drawString(textCoords);
	sprintf(text, "%.0lf FPS", fpsTimer->getFps());
	drawString(textCoords.moveByVector(0,2 * Constants::smallLetterSize));
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

void Painter::drawHealthBars()
{
	if (bothSidesAreAlive())
	{
		drawPlayerHealthBar();
		drawEnemyHealthBar();
	}
}

bool Painter::bothSidesAreAlive()
{
	return level->getEnemy()->getHitpoints() >= 0 && level->getPlayer()->getHitpoints() >= 0;
}

void Painter::drawPlayerHealthBar()
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

void Painter::drawEnemyHealthBar()
{
	int barSize = 10;
	double partOfLostHp = (static_cast<double>(level->getEnemy()->getHitpoints()) / Enemy::enemyMaxHealth);
	drawFillRectangle(Point(barSize,(1 - partOfLostHp) * (Constants::screenHeight - 2*barSize)), barSize, 
		partOfLostHp * (Constants::screenHeight - barSize), redColor);
}

void Painter::drawString(const Point& coords)
{
	const char* text = this->text;
	int xCoord = coords.getX(), yCoord = coords.getY();
	int px, py, c;
	SDL_Rect s, d;
	s.w = s.h = d.w = d.h = Constants::smallLetterSize;
	while (*text)
	{
		c = *text & 255;
		px = (c % 16) * Constants::smallLetterSize;
		py = (c / 16) * Constants::smallLetterSize;
		s.x = px;
		s.y = py;
		d.x = xCoord;
		d.y = yCoord;
		SDL_BlitSurface(charset, &s, screen, &d);
		xCoord += Constants::smallLetterSize;
		text++;
	}
}

void Painter::drawRectangle(const Point& coords, int width, int height, Uint32 outlineColor, Uint32 fillColor)
{
	drawOutlineRectangle(coords, width, height, outlineColor);
	drawFillRectangle(Point(coords).moveByVector(1,1), width-1, height-1, fillColor);
}

void Painter::drawFillRectangle(const Point& coords, int width, int height, Uint32 color)
{
	int yCoord = coords.getY();
	Point lineCoords = coords;
	for (int i = yCoord; i < yCoord + height; i++)
	{
		drawLine(lineCoords, width, 0, color);
		lineCoords.moveByVector(0, 1);
	}
}

void Painter::drawOutlineRectangle(const Point& coords, int width, int height, Uint32 color)
{
	Point lineCoords = coords;
	drawLine(lineCoords, height, 90, color);
	drawLine(lineCoords, width, 0, color);
	drawLine(lineCoords.moveByVector(width - 1, 0), height, 90, color);
	drawLine(lineCoords.moveByVector(1 - width, height - 1), width, 0, color);
}

void Painter::drawLine(const Point& coords, int length, int inclinationDegrees, Uint32 color)
{
	Point pixelCoords = coords;
	double degToRad = M_PI / 180;
	for (int i = 0; i < length; i++)
	{
		drawPixel(pixelCoords, color);
		pixelCoords.moveByVector(cos(inclinationDegrees * degToRad), sin(inclinationDegrees * degToRad));
	}
}

void Painter::drawObject(SDL_Surface* sprite, const Point& coords)
{
	SDL_Rect dest;
	dest.x = coords.getX() - sprite->w / 2;
	dest.y = coords.getY() - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
}

void Painter::drawPixel(const Point& coords, Uint32 color)
{
	int bpp = screen->format->BytesPerPixel;
	Uint8* p = (Uint8*)screen->pixels + coords.getY() * screen->pitch + coords.getX() * bpp;
	*(Uint32*)p = color;
}

Painter::~Painter()
{
	if(fpsTimer != nullptr)
		delete fpsTimer;
	SDL_FreeSurface(background);
	SDL_FreeSurface(charset);
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
}