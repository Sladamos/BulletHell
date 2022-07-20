#pragma once
#include "InterfaceElement.h"
#include "MenuPainter.h"
class MenuEngine : public InterfaceElement
{
public:
	MenuEngine(SDL_Window* window, SDL_Renderer* renderer);
	~MenuEngine();
	int getSelectedLevel();
	void start() override;
private:
	void handleMenuEvents();

	MenuPainter* menuPainter;
	int selectedLevel;
};


