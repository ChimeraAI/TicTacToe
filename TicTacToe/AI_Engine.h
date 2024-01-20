#pragma once
#include "Board.h"

class AI_Engine : public Board
{
private:
public:
	int minimax(char player, int depth);
	std::pair<int,int> getBestMove();
};

