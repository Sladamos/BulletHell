#pragma once
#include "InterfaceElement.h"
#include "VictoryPainter.h"
class VictoryEngine : public InterfaceElement
{
public:
	VictoryEngine(SDL_Window* window, SDL_Renderer* renderer);
	~VictoryEngine();
	void start() override;
private:
	void handleVictoryEvents();

	VictoryPainter* victoryPainter;
};

