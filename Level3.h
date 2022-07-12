#pragma once
#include "Level.h"
class Level3 : public Level
{
public:
	Level3(SDL_Window* window, SDL_Renderer* renderer);
private:
	virtual void createEnemies() override;
};
