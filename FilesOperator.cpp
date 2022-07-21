#include "FilesOperator.h"
#include <fstream>
using namespace std;

void FilesOperator::saveScore(const string& score)
{
	ofstream scoreFile("scores.dta", ios_base::app);
	if (scoreFile.is_open())
	{
		scoreFile.write(&score[0], score.length());
		scoreFile.close();
	}
}