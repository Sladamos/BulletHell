#include "GameObject.h"
#include "Painter.h"
#include "MathVector.h"

Painter::Painter(SDL_Window* window, SDL_Renderer* renderer) : window(window), renderer(renderer)
{
	screen = SDL_CreateRGBSurface(0, Constants::screenWidth, Constants::screenHeight, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, Constants::screenWidth, Constants::screenHeight);
	charset = SDL_LoadBMP("./gfx/cs8x8.bmp");
	setColors();
}

void Painter::updateTextureAndRenderer()
{
	SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, scrtex, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void Painter::setColors()
{
	blackColor = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	redColor = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	blueColor = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	SDL_SetColorKey(charset, true, 0x000000);
}

void Painter::drawString(const MathPoint& coords)
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

void Painter::drawRectangle(const MathPoint& coords, int width, int height, Uint32 outlineColor, Uint32 fillColor)
{
	drawOutlineRectangle(coords, width, height, outlineColor);
	drawFillRectangle(MathPoint(coords).moveByVector(MathVector(MathPoint(1,1))), width-1, height-1, fillColor);
}

void Painter::drawFillRectangle(const MathPoint& coords, int width, int height, Uint32 color)
{
	int yCoord = coords.getY();
	MathPoint lineCoords = coords;
	MathVector vector(MathPoint(0, 1));
	for (int i = yCoord; i < yCoord + height; i++)
	{
		drawLine(lineCoords, width, 0, color);
		lineCoords.moveByVector(vector);
	}
}

void Painter::drawOutlineRectangle(const MathPoint& coords, int width, int height, Uint32 color)
{
	MathPoint lineCoords = coords;
	drawLine(lineCoords, height, 90, color);
	drawLine(lineCoords, width, 0, color);
	drawLine(lineCoords.moveByVector(MathVector(MathPoint(width - 1, 0))), height, 90, color);
	drawLine(lineCoords.moveByVector(MathVector(MathPoint(1 - width, height - 1))), width, 0, color);
}

void Painter::drawLine(const MathPoint& coords, int length, int inclinationDegrees, Uint32 color)
{
	MathPoint pixelCoords = coords;
	double degToRad = M_PI / 180;
	MathVector vector(MathPoint(cos(inclinationDegrees * degToRad), sin(inclinationDegrees * degToRad)));
	for (int i = 0; i < length; i++)
	{
		drawPixel(pixelCoords, color);
		pixelCoords.moveByVector(vector);
	}
}

void Painter::drawObject(SDL_Surface* sprite, const MathPoint& coords)
{
	SDL_Rect dest;
	dest.x = coords.getX() - sprite->w / 2;
	dest.y = coords.getY() - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
}

void Painter::drawPixel(const MathPoint& coords, Uint32 color)
{
	int bpp = screen->format->BytesPerPixel;
	Uint8* p = (Uint8*)screen->pixels + coords.getY() * screen->pitch + coords.getX() * bpp;
	*(Uint32*)p = color;
}

Painter::~Painter()
{
	SDL_FreeSurface(charset);
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
}