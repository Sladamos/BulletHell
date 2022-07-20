#pragma once
#include "InterfaceElement.h"
#include "DefeatPainter.h"
class DefeatEngine : public InterfaceElement
{
public:
	DefeatEngine(SDL_Window* window, SDL_Renderer* renderer);
	~DefeatEngine();
	void start() override;
private:
	void handleDefeatEvents();

	DefeatPainter* defeatPainter;
};

