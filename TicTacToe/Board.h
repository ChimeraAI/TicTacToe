#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Board
{
private:
	char board[3][3] = { 
		{'-', '-', '-'},
		{'-', '-', '-'},
		{'-', '-', '-'} 
	};
public:
	Board();
	void CreateHeader();
	void CreateBoard();
	void Run();

};

