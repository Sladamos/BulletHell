#include "Level3.h"
#include "Enemy3.h"

Level3::Level3(SDL_Window* window, SDL_Renderer* renderer) : Level(window, renderer) {}

void Level3::createEnemies()
{
	addEnemy(new Enemy3("./gfx/demon3", MathPoint(700, 235), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy3("./gfx/demon3", MathPoint(120, 545), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy3("./gfx/demon3", MathPoint(1140, 910), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
	addEnemy(new Enemy3("./gfx/demon3", MathPoint(970, 350), std::vector<MathPoint>{MathPoint(-55, -55), MathPoint(-55, 55), MathPoint(55, 55), MathPoint(55, -55)}));
}