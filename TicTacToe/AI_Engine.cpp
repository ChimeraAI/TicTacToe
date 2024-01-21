#include "AI_Engine.h"

AI_Engine::AI_Engine() {}

AI_Engine::~AI_Engine() {}

int AI_Engine::minimax(char(board)[3][3], char player) {
    if (IsGameWon(board, PLAYER_MARKER)) {
        return -1;
    } else if (IsGameWon(board, AI_MARKER)) {
        return 1;
    } else if (IsBoardFull(board)) {
        return 0;
    }
    
    int bestScore = (player == AI_MARKER) ? INT_MIN : INT_MAX;
    int score = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == BLANK_MARKER) {
                board[i][j] = player;
                score = minimax(board, (player == AI_MARKER) ? PLAYER_MARKER : AI_MARKER);
                board[i][j] = BLANK_MARKER;
            }
            
            if ((player == PLAYER_MARKER && score < bestScore) || (player == AI_MARKER && score > bestScore)) {
                bestScore = score;
            }
        }
    }
    return bestScore;
}


std::pair<int,int> AI_Engine::getBestMove(char(board)[3][3]) {
	int bestScore = INT_MIN;
	int score = 0;
	int best_I_move = -1;
	int best_J_move = -1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == BLANK_MARKER) {
				board[i][j] = AI_MARKER;
				score = this->minimax(board, PLAYER_MARKER);
				board[i][j] = BLANK_MARKER;
			}

			if (score > bestScore && board[i][j] == BLANK_MARKER) {
				bestScore = score;
				best_I_move = i;
				best_J_move = j;
			}
		}
	}

	return std::make_pair(best_I_move, best_J_move);
}

bool AI_Engine::IsGameWon(char(board)[3][3], char player) {
	// Check rows and columns
	for (int i = 0; i < 3; ++i) {
		if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
			(board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
			return true; // Win in row or column
		}
	}

	// Check diagonals
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
		(board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
		return true; // Win in diagonal
	}
	return false;
}

bool AI_Engine::IsBoardFull(char(board)[3][3]) {
	// Check if the board is full (no BLANK_MARKER left)
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == BLANK_MARKER) {
				return false; // Board is not full
			}
		}
	}
	return true; // Board is full
}