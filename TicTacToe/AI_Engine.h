/*
Description: This header file defines the AI_Engine class, which encapsulates the game strategy for an AI opponent
in a Tic-Tac-Toe game. The class includes implementations of the Minimax algorithm for decision-making,
functions to determine the best move for the AI, and checks for game-winning conditions and a full game board.
*/

#pragma once

// Include necessary header files
#include <iostream>
// Contains macros
#include "Constant.h"

// Using declaration for standard library components
using std::cin;
using std::cout;
using std::endl;

// Class definition for the AI_Engine class
class AI_Engine {
private:
public:
	// Constructor
	AI_Engine();

	// Destructor
	~AI_Engine();

	// Function to implement the minimax algorithm for game strategy
	int minimax(char(board)[3][3], char player);

	// Function to get the best move using the minimax algorithm
	std::pair<int, int> getBestMove(char(board)[3][3]);

	// Function to check if the game board is full
	bool IsBoardFull(char(board)[3][3]);

	// Function to check if the game is won by a player
	bool IsGameWon(char(board)[3][3], char player);

};

