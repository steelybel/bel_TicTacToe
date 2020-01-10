#pragma once
#include <iostream>
struct Board
{
public:
	Board();
	Board(int b);
	int playerWin();
	void draw();
	void makeMove();
private:
	bool turn; //false = X's turn, true = O's turn
	int** bort;
	int bortSize;
	void setSize(int b);
	void place(int col, int row);
	const char* symb[3] = { "_", "X", "O" };
};