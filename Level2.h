#pragma once
#include "Level.h"
class Level2 : public Level
{
public:
	Level2(SDL_Window* window, SDL_Renderer* renderer);
private:
	virtual void createEnemies() override;
};
