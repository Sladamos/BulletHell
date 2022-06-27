#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include<string.h>
#include"./SDL2-2.0.10/include/SDL.h"
#include"./SDL2-2.0.10/include/SDL_main.h"
#include "Level.h"

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Level* level = new Level();
	level->startLevel();
	delete level;
	//TODO: abstract level and remember number in game class
	//TODO: game class which creates window(send to lvl to painter) and menu etc.
	//make lvl ptr and create next lvl if you won (delete and ask for continue) - if lose save score and back to menu
	SDL_Quit();
	return 0;
}
