#pragma once
#include <string>
#include <iostream>
class Score
{
public:
	Score(const std::string& nickname, int scoreValue);
	friend std::ostream& operator<<(std::ostream& os, const Score& score);
	friend bool scoresComparator(const Score& score1, const Score& score2);
	std::string toString() const;
private:
	std::string nickname;
	int scoreValue;
};

