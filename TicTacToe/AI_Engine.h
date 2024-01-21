#pragma once
#include <iostream>
#include "Constant.h"

using std::cin;
using std::cout;
using std::endl;

class AI_Engine {
private:
public:
	AI_Engine();
	~AI_Engine();

	int minimax(char(board)[3][3], char player);
	std::pair<int, int> getBestMove(char(board)[3][3]);

	bool IsBoardFull(char(board)[3][3]);
	bool IsGameWon(char(board)[3][3], char player);

};

