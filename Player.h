#pragma once
#include <thread>
#include <random>
#include <chrono>
class Player
{
private:
	int hits;
public:
	Player();
	Player(const Player&);
	void RandomHit();
	int GetHits();
};

Player::Player()
{
	hits = 0;
}

Player::Player(const Player& p)
{
	hits = p.hits;
}

void Player::RandomHit()
{
	std::random_device generator;
	std::uniform_int_distribution<int> distribute(0, 100);
	hits = distribute(generator);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int Player::GetHits()
{
	return hits;
}