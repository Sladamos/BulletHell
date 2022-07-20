#pragma once
#include "GameCommand.h"
class InterfaceElement
{
public:
	InterfaceElement();
	virtual ~InterfaceElement() = default;
	GameCommand getGameCommand();
	void setGameCommand(GameCommand command);
	virtual void start() = 0;
	bool isGameCommandUndefined();
protected:
	GameCommand commandToSend;
};

