#include "Level4.h"
#include "Enemy4.h"

Level4::Level4(SDL_Window* window, SDL_Renderer* renderer) : Level(window, renderer) {}

void Level4::createEnemies()
{
	addEnemy(new Enemy4("./gfx/demon4", MathPoint(700, 200), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy4("./gfx/demon4", MathPoint(1200, 500), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy4("./gfx/demon4", MathPoint(200, 800), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
}