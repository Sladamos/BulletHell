#pragma once
#include <string>
#include "Painter.h"
class ScoreSaverPainter : public Painter
{
public:
	ScoreSaverPainter(const std::string& nickname, SDL_Window* window, SDL_Renderer* renderer);
	void drawScreen() override;

	static constexpr int maxNickLength = 10;
private:
	void drawSaverInfo();

	const std::string& currentNick;
};

