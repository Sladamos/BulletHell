#pragma once
#include <map>
#include <string>
#include <vector>
#include "./SDL2-2.0.10/include/SDL.h"
#include "./SDL2-2.0.10/include/SDL_main.h"
class BmpManager
{
public:
	static void loadStaticBitmap(std::string objectName); //najpierw sprawdü czy istnieje juz bitmapa
	//static void loadAnimation(std::string objectName, int numberOfAnimations);
	static void getBitmap(std::string objectName);
	//static void getAnimation(std::string objectName, int numberOfAnimation);
	static void freeBitmaps();
private:
	//static void loadAnimation(std::string objectName);
	static std::map<std::string, std::vector<SDL_Surface*>> bitmaps;
};

//Bmp name structure : object name ; _lvl_ before level number if necessary ; _an_ before animation number ;
//examples:		player_an_1, player_an_2, player_an_3,
//examples:		bonus, wall, background
//examples:		enemy_lvl_1, enemy_lvl_2_an_1, enemy_lvl_2_an_2

