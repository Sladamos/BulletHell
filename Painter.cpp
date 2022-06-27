#include "GameObject.h"
#include "Painter.h"
#include "Level.h"

Painter::Painter(Level* level, SDL_Window* window, SDL_Renderer* renderer) : level(level), window(window), renderer(renderer)
{
	screen = SDL_CreateRGBSurface(0, Constans::screenWidth, Constans::screenHeight, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, Constans::screenWidth, Constans::screenHeight);
	charset = SDL_LoadBMP("./cs8x8.bmp");
	addFpsTimer();
	setColors();	//TODO: make abstract and menu will inherit after painter with new constructor(without fpstimer -> nullptr)
}

void Painter::addFpsTimer()
{
	fpsTimer = new FpsTimer(0.5);
	TimeManager::addTimer(fpsTimer);
}

void Painter::setColors()
{
	BLACK = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	RED = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	BLUE = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	SDL_SetColorKey(charset, true, 0x000000);
}

void Painter::drawScreen()
{
	SDL_FillRect(screen, NULL, BLACK);
	drawStatistics();
	printGameObjects();
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
	fpsTimer->incrementFrames();
}

void Painter::printGameObjects()
{
	for (GameObject* gameObject : level->getGameObjects())
		gameObject->print(this);	//TODO if is in camera range print
}

void Painter::drawStatistics()
{
	Point coords(4,4);
	drawRectangle(coords, Constans::screenWidth-8, 36, RED, BLUE);	//Panel for statistics - TODO refactor and make clear
	sprintf(text, "Szablon SDL, czas trwania = %.1lf s  %.0lf klatek / s", level->getLevelTimer()->getTimerValue(), fpsTimer->getFps());
	coords.setCoordinates(screen->w / 2 - strlen(text) * Constans::smallLetterSize / 2, 10);
	drawString(coords, text);
	sprintf(text, "Esc - wyjscie, \030 - przyspieszenie, \031 - zwolnienie");
	coords.setCoordinates(screen->w / 2 - strlen(text) * Constans::smallLetterSize / 2, 26);
	drawString(coords, text);
}

void Painter::drawString(const Point& coords, const char* text)
{
	int xCoord = coords.getX(), yCoord = coords.getY();
	int px, py, c;
	SDL_Rect s, d;
	s.w = s.h = d.w = d.h = Constans::smallLetterSize;
	while (*text)
	{
		c = *text & 255;
		px = (c % 16) * Constans::smallLetterSize;
		py = (c / 16) * Constans::smallLetterSize;
		s.x = px;
		s.y = py;
		d.x = xCoord;
		d.y = yCoord;
		SDL_BlitSurface(charset, &s, screen, &d);
		xCoord += Constans::smallLetterSize;
		text++;
	}
}

void Painter::drawRectangle(const Point& coords, int width, int height, Uint32 outlineColor, Uint32 fillColor)
{
	drawOutlineRectangle(coords, width, height, outlineColor);
	drawFillRectangle(coords, width, height, fillColor);
}

void Painter::drawFillRectangle(const Point& coords, int width, int height, Uint32 color)
{
	int yCoord = coords.getY();
	Point lineCoords = coords;
	lineCoords.moveByVertex(1, 0);
	for (int i = yCoord + 1; i < yCoord + height - 1; i++)
	{
		lineCoords.moveByVertex(0, 1);
		drawLine(lineCoords, width - 2, 0, color);
		drawLine(lineCoords, width - 2, 0, color);
	}
}

void Painter::drawOutlineRectangle(const Point& coords, int width, int height, Uint32 color)
{
	Point lineCoords = coords;
	drawLine(lineCoords, height, 90, color);
	drawLine(lineCoords, width, 0, color);
	lineCoords.moveByVertex(width - 1, 0);
	drawLine(lineCoords, height, 90, color);
	lineCoords.moveByVertex(1 - width, height - 1);
	drawLine(lineCoords, width, 0, color);
}

void Painter::drawLine(const Point& coords, int length, int inclinationDegrees, Uint32 color)
{
	Point pixelCoords = coords;
	double degToRad = M_PI / 180;
	for (int i = 0; i < length; i++)
	{
		drawPixel(pixelCoords, color);
		pixelCoords.moveByVertex(cos(inclinationDegrees * degToRad), sin(inclinationDegrees * degToRad));
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
	SDL_FreeSurface(charset);
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
}