#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <numeric>

#include "AI_Engine.h"
#include "Constant.h"

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

	AI_Engine aiInstance;

	// Define winning combinations using integers
	std::vector<std::vector<int>> winningPositions = {
		{0, 1, 2}, // Row 1
		{3, 4, 5}, // Row 2
		{6, 7, 8}, // Row 3
		{0, 3, 6}, // Column 1
		{1, 4, 7}, // Column 2
		{2, 5, 8}, // Column 3
		{0, 4, 8}, // Diagonal 1
		{2, 4, 6}  // Diagonal 2
	};

	void CreateHeader();
	void CreateBoard();
	void BeginGame();

	std::pair<int, bool> CheckGameState();

	void AIMakeMove();

	void UpdateMove();

	bool IsPositionOccupied(std::pair<int, int> pos);

	std::pair<int, int> GetPlayerMove();
	void PlayerMakeMove(int row, int col);
	bool IsLegalMove(int row, int col);

	// Functions for controlling restarting or ending the game
	bool PlayAgain();
	void RestartGame();
	void TestFunc();

	// Functions for displaying in terminal
	void ClearTerminal();
	void PrintBoard();
	void RefreshScreen();


public:
	Board();
	~Board();

	void Run();

	bool IsBoardFull(char (&board)[3][3]);
	bool IsGameWon(char(&board)[3][3], char player);
	bool IsGameLoss(char(&board)[3][3], char player);

};

