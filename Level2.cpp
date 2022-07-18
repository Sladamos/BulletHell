#include "Level2.h"
#include "Enemy2.h"

Level2::Level2(SDL_Window* window, SDL_Renderer* renderer) : Level(window, renderer) {}

void Level2::createEnemies()
{
	addEnemy(new Enemy2("./gfx/demon2", MathPoint(700, 200), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy2("./gfx/demon2", MathPoint(1200, 500), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy2("./gfx/demon2", MathPoint(1285, 430), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy2("./gfx/demon2", MathPoint(1160, 610), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
}