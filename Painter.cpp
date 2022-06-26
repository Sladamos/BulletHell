#include "Painter.h"
#include "Level.h"
#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480
#define LETTER_SIZE 8

Painter::Painter(Level* level) : level(level)
{
	createWindowAndRenderer();
	screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	charset = SDL_LoadBMP("./cs8x8.bmp");
	addFpsTimer();
	setColors();
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
}

void Painter::createWindowAndRenderer()
{
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Szablon SDL2");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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

	//DrawSprite(screen, charset, SCREEN_WIDTH / 2 + sin(distance) * SCREEN_HEIGHT / 3, SCREEN_HEIGHT / 2 + cos(distance) * SCREEN_HEIGHT / 3);
	drawStatistics();
	//print sprites
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
	fpsTimer->incrementFrames();
}

void Painter::drawStatistics()
{
	drawRectangle(4, 4, SCREEN_WIDTH-8, 36, RED, BLUE);	//Panel for statistics
	sprintf(text, "Szablon SDL, czas trwania = %.1lf s  %.0lf klatek / s", level->getLevelTimer()->getTimerValue(), fpsTimer->getFps());
	drawString(screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
	sprintf(text, "Esc - wyjscie, \030 - przyspieszenie, \031 - zwolnienie");
	drawString(screen->w / 2 - strlen(text) * LETTER_SIZE / 2, 26, text, charset);
}

void Painter::drawString(int xCoord, int yCoord, const char* text, SDL_Surface* charset)
{
	int px, py, c;
	SDL_Rect s, d;
	s.w = s.h = d.w = d.h = LETTER_SIZE;
	while (*text)
	{
		c = *text & 255;
		px = (c % 16) * LETTER_SIZE;
		py = (c / 16) * LETTER_SIZE;
		s.x = px;
		s.y = py;
		d.x = xCoord;
		d.y = yCoord;
		SDL_BlitSurface(charset, &s, screen, &d);
		xCoord += LETTER_SIZE;
		text++;
	}
}

void Painter::drawRectangle(int xCoord, int yCoord, int width, int height, Uint32 outlineColor, Uint32 fillColor)
{
	drawLine(xCoord, yCoord, height, 90, outlineColor);
	drawLine(xCoord + width - 1, yCoord, height, 90, outlineColor);
	drawLine(xCoord, yCoord, width, 0, outlineColor);
	drawLine( xCoord, yCoord + height - 1, width, 0, outlineColor);
	for (int i = yCoord + 1; i < yCoord + height - 1; i++)
		drawLine(xCoord + 1, i, width - 2, 0, fillColor);
}

void Painter::drawLine(int xCoord, int yCoord, int length, int inclinationDegrees, Uint32 color)
{
	for (int i = 0; i < length; i++)
	{
		drawPixel(xCoord, yCoord, color);
		xCoord += cos(inclinationDegrees * M_PI / 180);
		yCoord += sin(inclinationDegrees * M_PI / 180);
	}
}

void Painter::drawSprite(SDL_Surface* sprite, int xCoord, int yCoord)
{
	SDL_Rect dest;
	dest.x = xCoord - sprite->w / 2;
	dest.y = yCoord - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
}

void Painter::drawPixel(int xCoord, int yCoord, Uint32 color)
{
	int bpp = screen->format->BytesPerPixel;
	Uint8* p = (Uint8*)screen->pixels + yCoord * screen->pitch + xCoord * bpp;
	*(Uint32*)p = color;
}

Painter::~Painter()
{
	delete fpsTimer;
	SDL_FreeSurface(charset);
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}