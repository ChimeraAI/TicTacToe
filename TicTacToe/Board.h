#pragma once
#include <iostream>
#include <vector>
#include <array>

#define PLAYER_MARKER 'X'
#define AI_MARKER 'O'

#define WIN 1
#define DRAW 0
#define LOSS -1
#define INPROGESS 11

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

	std::vector<std::vector<std::pair<int, int>>> winning_moves{
		// Diagonal
		{ std::make_pair(0, 0), std::make_pair(1, 1), std::make_pair(2, 2) },
		{ std::make_pair(2, 0), std::make_pair(1, 1), std::make_pair(0, 2) },

		// Column
		{ std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(2, 0) },
		{ std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(2, 1) },
		{ std::make_pair(0, 2), std::make_pair(1, 2), std::make_pair(2, 2) },

		// Row
		{ std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2) },
		{ std::make_pair(1, 0), std::make_pair(1, 1), std::make_pair(1, 2) },
		{ std::make_pair(2, 0), std::make_pair(2, 1), std::make_pair(2, 2) }

	};

public:
	Board();
	~Board();

	void CreateHeader();
	void CreateBoard();
	void BeginGame();

	std::pair<int,bool> CheckGameState();
	bool IsBoardFull();
	bool IsGameWon();
	bool IsGameLoss();

	void UpdateMove();

	bool IsPositionOccupied(std::pair<int, int> pos);
	
	std::pair<int, int> GetPlayerMove();
	void PlayerMakeMove();
	void AIMakeMove();
	std::vector<std::pair<int, int>> GetLegalMoves();

	bool PlayAgain();

	void Run();

};

