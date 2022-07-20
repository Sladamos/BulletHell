#include "InterfaceElement.h"

InterfaceElement::InterfaceElement() : commandToSend(GameCommand::undefined) {}

GameCommand InterfaceElement::getGameCommand()
{
	return commandToSend;
}

void InterfaceElement::setGameCommand(GameCommand command)
{
	this->commandToSend = command;
}

bool InterfaceElement::isGameCommandUndefined()
{
	return commandToSend == GameCommand::undefined;
}
