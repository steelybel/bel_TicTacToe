//board.cpp
#include "board.h"
Board::Board()
{
	setSize(3);
	turn = false;
}

Board::Board(int b)
{
	setSize(b);
	turn = false;
}

void Board::draw()
{
	system("CLS");
	for (int c = 0; c < bortSize; c++) //ahaha its like the language! hehehe! get it? ahhahaha!
	{
		//Print column numbers at top, ends line to start actually drawing the board
		if (c == 0)
		{
			for (int r = 0; r < bortSize; r++)
			{
				if (r == 0)
				{
					std::cout << "  ";
				}
				std::cout << r;
				std::cout << " ";
			}
			std::cout << std::endl;
		}
		for (int r = 0; r < bortSize; r++)
		{
			//Print divider + row numbers at left
			if (r == 0)
			{
				std::cout << c << "|";
			}
			std::cout << symb[bort[c][r]];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}
void Board::makeMove()
{
	std::cout << std::endl;
	std::cout << "Player " << ((turn)?"O ":"X ") << std::endl;
	int row = -1;
	int col = -1;
	std::cout << "Enter row (across)";
	while (row < 0 || row >= bortSize)
	{
		std::cin >> row;
		std::cout << std::endl;
		if (row < 0 || row >= bortSize)
		{
			std::cout << "Illegal row. Try again >";
		}
	}
	std::cin.ignore();
	std::cout << "Enter column (down)";
	while (col < 0 || col >= bortSize)
	{
		std::cin >> col;
		std::cout << std::endl;
		if (col < 0 || col >= bortSize)
		{
			std::cout << "Illegal column. Try again >";
			std::cin.ignore();
		}
	}
	if (bort[col][row] > 0)
	{
		std::cout << "The space is already taken. Press any key to try again.";
		std::cin;
		return;
	}
	place(col, row);
	turn = !turn;
}
void Board::setSize(int b)
{
	bort = new int*[b];
	for (int i = 0; i < b; i++) {
		bort[i] = new int[b];
	}
	bortSize = b;
	for (int c = 0; c < bortSize; c++)
	{
		for (int r = 0; r < bortSize; r++)
		{
			bort[c][r] = 0;
		}
	}
}
void Board::place(int col, int row)
{
	int p = ((turn) ? 2 : 1);
	bort[col][row] = p;
}
int Board::playerWin()
{
	//horiz check
	for (int c = 0; c < bortSize; c++)
	{
		if (bort[c][0] > 0)
		{
			for (int r = 0; r < bortSize; r++)
			{
				if (bort[c][r] != bort[c][0]) break;
				else if (bort[c][bortSize - 1] == bort[c][0]) return bort[c][0];
			}
		}
	}
	//vert check
	for (int r = 0; r < bortSize; r++)
	{
		if (bort[0][r] > 0)
		{
			for (int c = 0; c < bortSize; c++)
			{
				if (bort[c][r] != bort[0][r]) break;
				else if (bort[bortSize - 1][r] == bort[0][r]) return bort[0][r];
			}
		}
	}
	//diag check 1 - starting from topleft
	for (int c = 0; c < bortSize; c++)
	{
		if (bort[0][0] > 0)
		{
			for (int r = 0; r < bortSize; r++)
			{
				if (bort[c][c] != bort[0][0]) break;
				else if (bort[bortSize - 1][bortSize - 1] == bort[0][0]) return bort[0][0];
			}
		}
	}
	//diag check 2 - starting from bottomleft
	for (int c = bortSize - 1; c >= 0; c--)
	{
		if (bort[0][bortSize - 1] > 0)
		{
			for (int r = 0; r < bortSize; r++)
			{
				if (bort[(bortSize - 1) - r][r] != bort[0][bortSize - 1]) break;
				else if (bort[bortSize - 1][0] == bort[0][bortSize - 1]) return bort[0][bortSize - 1];
			}
		}
	}
	//check for a tie - if the board is filled, the game will know a tie exists!
	int tieCheck = 0;
	for (int c = 0; c < bortSize; c++)
	{
		for (int r = 0; r < bortSize; r++)
		{
			if (bort[c][r] != 0)
			{
				tieCheck++;
			}
		}
	}
	if (tieCheck == (bortSize * bortSize))
	{
		return 3;
	}
	return 0;
}