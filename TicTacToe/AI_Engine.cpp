#include "AI_Engine.h"

int AI_Engine::minimax(char player, int depth) {
	if (Board::IsGameWon(PLAYER_MARKER)) {
		return -1;
	}
	else if (Board::IsGameWon(AI_MARKER)) {
		return 1;
	}
	else if (Board::IsBoardFull()) {
		return 0;
	}
	
	int bestScore = (player == AI_MARKER) ? INT_MIN : INT_MAX;
	int score;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Board::board[i][j] == BLANK_MARKER) {
				Board::board[i][j] = player;
				score = minimax((player == AI_MARKER) ? PLAYER_MARKER : AI_MARKER, depth + 1);
				Board::board[i][j] == BLANK_MARKER;
			}
			
			if ((player == PLAYER_MARKER && score > bestScore) || (player == AI_MARKER && score < bestScore)) {
				bestScore = score;
			}

		}
	}
	return bestScore - depth;

}

std::pair<int,int> AI_Engine::getBestMove() {
	int bestScore = INT_MIN;
	int score;
	int best_I_move;
	int best_J_move;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Board::board[i][j] == BLANK_MARKER) {
				Board::board[i][j] = AI_MARKER;
				score = this->minimax(PLAYER_MARKER, 0);
				Board::board[i][j] = BLANK_MARKER;
			}

			if (score > bestScore) {
				bestScore = score;
				best_I_move = i;
				best_J_move = j;
			}
		}
	}

	return std::make_pair(best_I_move, best_J_move);
}