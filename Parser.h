#pragma once
#include <vector>
#include <string>
class Parser
{
public:
	bool isCorrectScoreLine(const std::vector<std::string>& tokenizedLine);
	bool isNumber(const std::string& num);
	bool isNicknameCreatedWithAllowedCharacters(const std::string& nick);
	bool isScoreValueCorrect(const std::vector<std::string>& tokenizedLine);
	bool isNicknameCorrect(const std::vector<std::string>& tokenizedLine);
};

