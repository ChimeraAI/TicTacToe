/*
 Description: 
 This header file defines the Board class, which represents the game board for a Tic-Tac-Toe game.
 It includes declarations for functions to run the game, check game states, make moves, and manage
 the interaction between players and an AI opponent.
 
*/

#pragma once

// Include necessary header files
#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <numeric>

// Include custom header files
#include "AI_Engine.h"
#include "Constant.h"

// Using declarations for standard library components
using std::cin;
using std::cout;
using std::endl;

// Class decitin
class Board
{
private:
	
	// Vector to store open positions on the board
	std::vector<int> open_positions{0,1,2,3,4,5,6,7,8}; // Continue coding here to update positions that are availiable

	// 2D array representing the Tic-Tac-Toe board
	char board[3][3] = { 
		{BLANK_MARKER,BLANK_MARKER,BLANK_MARKER},
		{BLANK_MARKER,BLANK_MARKER,BLANK_MARKER},
		{BLANK_MARKER,BLANK_MARKER,BLANK_MARKER}
	};

	// Instance of the AI Engine class for AI to make moves
	AI_Engine aiInstance;

	// Function to create header for the game
	void CreateHeader();

	// Function to initialize the board
	void CreateBoard();

	// Function to begin the game
	void BeginGame();

	// Function to check current state of the game
	std::pair<int, bool> CheckGameState();

	// Function for AI to make a move
	void AIMakeMove();

	// Function to update the player's move
	void UpdateMove();

	// Function to check if a position on the board is occupied
	bool IsPositionOccupied(std::pair<int, int> pos);

	// Function to get the player's move
	std::pair<int, int> GetPlayerMove();

	// 
	void PlayerMakeMove(int row, int col);
	bool IsLegalMove(int row, int col);

	// Functions for controlling restarting or ending the game
	bool PlayAgain();
	void RestartGame();

	// Functions for displaying in terminal
	void ClearTerminal();
	void PrintBoard();
	void RefreshScreen();

public:
	// Constructor
	Board();

	// Destructor
	~Board();

	// Function to run the game
	void Run();

	// Function to check if the board is full
	bool IsBoardFull(char (&board)[3][3]);

	// Function to check if targeted player won the game
	bool IsGameWon(char(&board)[3][3], char player);
	bool IsGameLoss(char(&board)[3][3], char player);
};

