#include "Level1.h"
#include "Enemy1.h"

Level1::Level1(SDL_Window* window, SDL_Renderer* renderer) : Level(window, renderer) {}

void Level1::createEnemies()
{
	addEnemy(new Enemy1("./gfx/demon1", MathPoint(300, 750), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy1("./gfx/demon1", MathPoint(400, 750), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy1("./gfx/demon1", MathPoint(1200, 300), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy1("./gfx/demon1", MathPoint(1200, 1000), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy1("./gfx/demon1", MathPoint(355, 890), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy1("./gfx/demon1", MathPoint(750, 120), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
}