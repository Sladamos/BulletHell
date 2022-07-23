#include <iomanip>
#include <sstream>
#include "Score.h"
#include "ScoreSaverEngine.h"
using namespace std;

Score::Score(const string& nickname, int scoreValue) : nickname(nickname), scoreValue(scoreValue) {}

string Score::toString() const
{
	stringstream a_stream;
	a_stream << setiosflags(ios_base::right) << "Nick: " << nickname << string(ScoreSaverEngine::maxNickLength - nickname.length(), '.') <<
		" Score: " << string(6 - to_string(scoreValue).length(), '0') << to_string(scoreValue);
	return a_stream.str();
}

ostream& operator<<(ostream& os, const Score& score) 
{
	return os << score.toString();
}

bool scoresComparator(const Score& score1, const Score& score2)
{
	return score1.scoreValue > score2.scoreValue;
}