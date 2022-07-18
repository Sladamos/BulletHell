#pragma once
#include <map>
#include <string>
#include <vector>
#include "Shape.h"
#include "MathPoint.h"
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class BmpManager
{
public:
	static void loadStaticBitmap(const std::string& objectName, const std::vector<MathPoint>& corners);
	static void loadStaticBitmap(const std::string& objectName, int radius);
	static void loadAnimation(const std::string& objectName, const std::vector<MathPoint>& corners, int numberOfAnimations);
	static void loadAnimation(const std::string& objectName, int radius, int numberOfAnimations);
	static SDL_Surface* getBitmap(const std::string& objectName);
	static SDL_Surface* getAnimation(const std::string&, int numberOfAnimation);
	static void freeBitmaps();
private:
	static void addStaticBitmap(const std::string& objectName);
	static void addAnimations(const std::string& objectName, int numberOfAnimations);
	static void addShapeAndVector(const std::string& objectName, Shape* shape);
	static bool isntLoadedAlready(const std::string& objectName);

	static std::map<std::string, std::vector<SDL_Surface*>> bitmaps;
};

//Bmp name structure : object name ; _an_ before animation number ;
//examples:		player_an_1, player_an_2, player_an_3,
//examples:		bonus, wall, background
//examples:		enemy1, enemy2_an_1, enemy2_an_2

