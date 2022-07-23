#pragma once
#include <string>
#include "InterfaceElement.h"
#include "ScoreSaverPainter.h"
class ScoreSaverEngine : public InterfaceElement
{
public:
	ScoreSaverEngine(SDL_Window* window, SDL_Renderer* renderer);
	~ScoreSaverEngine();
	void start() override;

	static constexpr int maxNickLength = 10;
private:
	void handleSaverEvents();
	void saveScore();

	ScoreSaverPainter* saverPainter;
	std::string nickname;
};

