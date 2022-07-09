#pragma once
#include "Level.h"
class Level1 : public Level
{
public:
	Level1(SDL_Window* window, SDL_Renderer* renderer);
private:
	virtual void createEnemies() override;
};

