#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "Score.h"
#include "Parser.h"
class FilesOperator
{
public:
	static void saveScore(const Score& score);
	static std::vector<Score> loadScores();
private:
	static void saveSortedScores(const std::vector<Score>& loadedScores);
	static void loadScoresFromFile(std::vector<Score>& loadedScores, std::ifstream& scoresFile);
	static std::vector<std::string> tokenize(const std::string& string);

	static Parser stringsParser;
};

