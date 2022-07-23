#include <algorithm>
#include <iterator>
#include "Parser.h"
using namespace std;

bool Parser::isCorrectScoreLine(const vector<string>& tokenizedLine)
{
	return tokenizedLine.size() == 4 && isNicknameCorrect(tokenizedLine) && isScoreValueCorrect(tokenizedLine);
}

bool Parser::isNicknameCorrect(const vector<string>& tokenizedLine)
{
	return tokenizedLine[0] == "Nick:" && isNicknameCreatedWithAllowedCharacters(tokenizedLine[1]) && tokenizedLine[1].size() <= 10;
}

bool Parser::isScoreValueCorrect(const vector<string>& tokenizedLine)
{
	return tokenizedLine[2] == "Score:" && isNumber(tokenizedLine[3]) && tokenizedLine[3].size() <= 6;
}

bool Parser::isNicknameCreatedWithAllowedCharacters(const string& nick)
{
	return !nick.empty() && 'A' <= nick[0] && nick[0] <= 'Z' && 
		all_of(next(nick.begin()), nick.end(), [](char c) {return 'a' <= c && c <= 'z' || c == '.'; });
}

bool Parser::isNumber(const string& num)
{
	return !num.empty() && all_of(num.begin(), num.end(), ::isdigit);
}