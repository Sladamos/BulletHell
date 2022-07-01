#include "Level1.h"
#include "Enemy.h"

Level1::Level1(SDL_Window* window, SDL_Renderer* renderer) : Level(window, renderer) {}

void Level1::createEnemy()
{
	gameObjects.push_back(new Enemy("./gfx/eti", std::vector<Point>{Point(-45, -45), Point(-45, 45), Point(45, -45), Point(45, 45)}));
}