//main.cpp
#include "board.h"
int main()
{
	bool game = true;
	int size = 0;
	Board ttt = Board();
	
	//prompts the player to enter size of board
	std::cout << "Input board size >";
	while (size <= 0)
	{
		std::cin >> size;
		std::cout << std::endl;
		if (size <= 0)
		{
			std::cout << "Illegal board size. Try again >";
		}
	}
	ttt = Board(size);
	while (game)
	{
		ttt.draw();
		ttt.makeMove();
		if (ttt.playerWin() > 0) //check for if a player won or there is a draw
		{
			ttt.draw();
			if (ttt.playerWin() < 3) //player won
			{
				std::cout << std::endl << ((ttt.playerWin() == 2) ? "O wins" : "X wins") << std::endl;
			}
			else //draw
			{
				std::cout << std::endl << "Draw game! Nobody wins." << std::endl;
			}
			std::cout << "Enter new board size to play again >";
			size = 0;
			while (size <= 0)
			{
				std::cin >> size;
				std::cout << std::endl;
				if (size <= 0)
				{
					std::cout << "Illegal board size. Try again >";
				}
			}
			ttt = Board(size);
		}
	}
	
	return 0;
}