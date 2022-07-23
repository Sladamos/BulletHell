#include <sstream>
#include <algorithm>
#include "FilesOperator.h"
using namespace std;

Parser FilesOperator::stringsParser = Parser();

void FilesOperator::saveScore(const Score& score)
{
	ofstream scoresFile("scores.dta", ios_base::app);
	if (scoresFile.is_open())
	{
		scoresFile << score << "\n";
		scoresFile.close();
	}
}

void FilesOperator::saveSortedScores(const vector<Score>& loadedScores)
{
	ofstream scoresFile("scores.dta", ios::out | ios::trunc);
	if (scoresFile.is_open())
	{
		for(Score score : loadedScores)
			scoresFile << score << "\n";
		scoresFile.close();
	}
}

vector<Score> FilesOperator::loadScores()
{
	ifstream scoresFile("scores.dta", ios_base::in);
	vector<Score> loadedScores;
	if (scoresFile.is_open())
	{
		loadScoresFromFile(loadedScores, scoresFile);
		sort(loadedScores.begin(), loadedScores.end(), scoresComparator);
		scoresFile.close();
		saveSortedScores(loadedScores);
	}
	return loadedScores;
}

void FilesOperator::loadScoresFromFile(vector<Score>& loadedScores, ifstream& scoresFile)
{
	string readedLine;
	while (getline(scoresFile, readedLine))
	{
		vector<string> tokenizedLine = tokenize(readedLine);
		if (stringsParser.isCorrectScoreLine(tokenizedLine))
			loadedScores.push_back(Score(tokenizedLine[1], stoi(tokenizedLine[3])));
	}
}

vector<string> FilesOperator::tokenize(const string& readedLine)
{
	stringstream ss(readedLine);
	string token;
	vector<string> tokenizedLine;
	while (ss >> token) 
		tokenizedLine.push_back(token);
	return tokenizedLine;
}
