#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <numeric>

#define PLAYER_MARKER 'X'
#define AI_MARKER 'O'
#define BLANK_MARKER '_'

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
	
	std::vector<int> open_positions{0,1,2,3,4,5,6,7,8}; // Continue coding here to update positions that are availiable

	char board[3][3] = { 
		{BLANK_MARKER,BLANK_MARKER,BLANK_MARKER},
		{BLANK_MARKER,BLANK_MARKER,BLANK_MARKER},
		{BLANK_MARKER,BLANK_MARKER,BLANK_MARKER}
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
	void PlayerMakeMove(int row, int col);
	void AIMakeMove();
	bool IsLegalMove(int row,int col);

	bool PlayAgain();

	void Run();

	void TestFunc();

	void ClearTerminal();

	void PrintBoard();

	void RefreshScreen();
};

