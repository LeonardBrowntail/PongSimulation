#include "Player.h"
#include "Score.h"
#include <iostream>

Score score;

int main()
{
	//Random number generator
	std::mt19937_64 generator;
	std::uniform_int_distribution<int> distribute(0, 1);

	Player playerX;
	Player playerY(playerX);
	const int WIN = 10;

	//Determines who moves first
	short turn;
	turn = distribute(generator);

	//Show who moves first
	if (turn == 0)
	{
		std::cout << "Player 1 moves first!\n";
	}
	else
	{
		std::cout << "Player 2 moves first!\n";
	}

	//Do the game loop until one of the players has 10 points
	do
	{
		if (turn == 0)
		{
			//Shows it is player 1's turn
			std::cout << "It is player 1's turn:\n";

			//Starting thread for player 1
			//Generating random number
			std::thread xThread(&Player::RandomHit, &playerX);
			xThread.join();

			//Shows player 1's hit point
			std::cout << "Player one made " << playerX.GetHits() << " hits!";

			//Detect if player 1 has less than 51 hit points
			if (playerX.GetHits() < 51)
			{
				//Add score to player 2 and show that player 1 gained a point
				score.addScore(1);
				std::cout << " Player 2 got a point!\n\n";
			}
			//If player 1 has more than 50 hit points
			else if (playerX.GetHits() > 50)
			{
				//Change turn and shows it
				std::cout << " Change turn!\n\n";
				turn = 1;
			}
		}
		else
		{
			//Shows it is player 2's turn
			std::cout << "It is player 2's turn:\n";

			//Starting thread for player 2
			//Generating random number
			std::thread yThread(&Player::RandomHit, &playerY);
			yThread.join();

			//Shows player 1's hit point
			std::cout << "Player one made " << playerX.GetHits() << " hits!";

			//Detect if player 2 has less than 51 hit points
			if (playerY.GetHits() < 51)
			{
				//Add score to player 1 and show that player 2 gained a point
				score.addScore(0);
				std::cout << " Player 2 got a point!\n\n";
			}
			//If player 2 has more than 50 hit points
			else if (playerY.GetHits() > 50)
			{
				//Change turn and shows it
				std::cout << " Change turn!\n\n";
				turn = 0;
			}
		}
	} while (score.getScore(0) < WIN && score.getScore(1) < WIN);

	//Show who won the game
	if (score.getScore(0) == WIN)
	{
		std::cout << "Player 1 wins with player 2 having " << score.getScore(1) << " point(s)!\n";
	}
	else
	{
		std::cout << "Player 2 wins with player 1 having " << score.getScore(0) << " point(s)!\n";
	}
}