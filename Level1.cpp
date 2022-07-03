#include "Level1.h"
#include "Enemy.h"

Level1::Level1(SDL_Window* window, SDL_Renderer* renderer) : Level(window, renderer) {}

void Level1::createEnemy()
{
	gameObjects.push_back(new Enemy("./gfx/eti", std::vector<MathPoint>{MathPoint(-45, -45), MathPoint(-45, 45), MathPoint(45, -45), MathPoint(45, 45)}));
}