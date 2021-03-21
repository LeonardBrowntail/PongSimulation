#pragma once
class Score
{
private:
	int score[2];
public:
	Score();
	void addScore(int);
	int getScore(int);
};

Score::Score()
{
	score[0] = 0;
	score[1] = 0;
}

void Score::addScore(int id)
{
	score[id] += 1;
}

int Score::getScore(int id)
{
	return score[id];
}