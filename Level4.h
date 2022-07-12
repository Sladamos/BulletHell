#pragma once
#include "Level.h"
class Level4 : public Level
{
public:
	Level4(SDL_Window* window, SDL_Renderer* renderer);
private:
	virtual void createEnemies() override;
};
