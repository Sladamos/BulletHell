#include "Level1.h"
#include "Enemy1.h"

Level1::Level1(SDL_Window* window, SDL_Renderer* renderer) : Level(window, renderer) {}

void Level1::createEnemy()
{
	gameObjects.push_back(new Enemy1("./gfx/demon1", MathPoint(400,500), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, -55), MathPoint(55, 55)}));
}