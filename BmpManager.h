#pragma once
#include <map>
#include <string>
#include <vector>
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class BmpManager
{
public:	//TODO: add animations
	static void loadStaticBitmap(const std::string& objectName);
	//static void loadAnimation(const std::string& objectName, int numberOfAnimations);
	static SDL_Surface* getBitmap(const std::string& objectName);
	//static void getAnimation(const std::string&, int numberOfAnimation);
	static void freeBitmaps();
private:
	//static void loadAnimation(const std::string& objectName);
	static std::map<std::string, std::vector<SDL_Surface*>> bitmaps;
};

//Bmp name structure : object name ; _lvl_ before level number if necessary ; _an_ before animation number ;
//examples:		player_an_1, player_an_2, player_an_3,
//examples:		bonus, wall, background
//examples:		enemy_lvl_1, enemy_lvl_2_an_1, enemy_lvl_2_an_2

