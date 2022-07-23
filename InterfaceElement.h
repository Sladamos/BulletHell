#pragma once
#include "Game.h"
class InterfaceElement
{
public:
	InterfaceElement();
	virtual ~InterfaceElement() = default;
	Game::Command getGameCommand();
	bool isGameCommandUndefined();
	void setGameCommand(Game::Command command);
	virtual void start() = 0;
protected:
	Game::Command commandToSend;
};

