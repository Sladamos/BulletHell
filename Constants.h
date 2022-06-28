#pragma once
class Constants
{
public:
	static constexpr int maxTextLength = 128;
	static constexpr int screenWidth = 640;
	static constexpr int screenHeight = 480;
	static constexpr int levelWidth = screenWidth;
	static constexpr int levelHeight = screenHeight;
	static constexpr int horizontalSpeedMultiplier = (screenWidth/4);	//Statistic width is 1/4 of screen width
	static constexpr int verticalSpeedMultiplier = (screenHeight/3);
	static constexpr int smallLetterSize = 8;
};