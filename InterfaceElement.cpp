#include "InterfaceElement.h"

InterfaceElement::InterfaceElement() : commandToSend(Game::Command::undefined) {}

Game::Command InterfaceElement::getGameCommand()
{
	return commandToSend;
}

void InterfaceElement::setGameCommand(Game::Command command)
{
	this->commandToSend = command;
}

bool InterfaceElement::isGameCommandUndefined()
{
	return commandToSend == Game::Command::undefined;
}
