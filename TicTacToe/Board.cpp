#include "Board.h"

Board::Board() {}

Board::~Board() {}

void Board::CreateHeader() {
	cout << "Tic Tac Toe " << endl;
	cout << "Player = X  AI Computer = O" << endl;
}

void Board::CreateBoard() {
	cout << endl;
	cout << this->board[0][0] << " " << this->board[0][1] << " " << this->board[0][2] << endl;
	cout << this->board[1][0] << " " << this->board[1][1] << " " << this->board[1][2] << endl;
	cout << this->board[2][0] << " " << this->board[2][1] << " " << this->board[2][2] << endl;
}

void Board::PrintBoard() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << this->board[i][j] << ' ';
		}
		cout << endl;
	}
}

void Board::TestFunc() {

	int a = this->occupiedPosition[2][2];
	cout << a << endl;
/*
	std::pair<int, int> playerMove = this->GetPlayerMove();
	this->board[playerMove.first][playerMove.second] = PLAYER_MARKER;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << this->board[i][j] << ' ';
		}
		cout << endl;
	}
*/

}

void Board::Run() {
	this->TestFunc();
/*
	this->CreateHeader();
	this->CreateBoard();
	this->BeginGame();
*/
}

void Board::BeginGame() {
	bool status = true;
	while (status) {
		while (!this->CheckGameState().second) {
			this->UpdateMove();
		}
		status = this->PlayAgain();
	}
}

bool Board::PlayAgain() {
	char decision;
	bool booleanDecision = false;
	cout << "Do you want to play again? (Y/N): ";
	cin >> decision;
	// Need error handling here
	if (decision == 'Y' || decision == 'y') {
		this->RestartGame();
		booleanDecision = true;
	}
	else if (decision == 'N' || decision == 'n') {
		booleanDecision = false;
	}
	return booleanDecision;
}

void Board::RestartGame() {
	this->ClearTerminal();
	this->CreateHeader();
	// Reset the board
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			this->board[i][j] = BLANK_MARKER;
		}
	}
	this->PrintBoard();
}

std::pair<int,bool> Board::CheckGameState() {
	if (this->IsGameWon(PLAYER_MARKER)) {
		return std::make_pair(WIN, true);
	}
	if (this->IsGameLoss(PLAYER_MARKER)) {
		return std::make_pair(LOSS, true);
	}
	if (this->IsBoardFull()) {
		return std::make_pair(DRAW,true);
	}
	return std::make_pair(INPROGESS, false);
}

bool Board::IsGameWon(char player) {
	// Check rows and columns
	for (int i = 0; i < 3; ++i) {
		if ((this->board[i][0] == player && this->board[i][1] == player && this->board[i][2] == player) ||
			(this->board[0][i] == player && this->board[1][i] == player && this->board[2][i] == player)) {
			cout << "You Won!" << endl;
			return true; // Win in row or column
		}
	}

	// Check diagonals
	if ((this->board[0][0] == player && this->board[1][1] == player && this->board[2][2] == player) ||
		(this->board[0][2] == player && this->board[1][1] == player && this->board[2][0] == player)) {
		cout << "You Won!" << endl;
		return true; // Win in diagonal
	}
	return false;
}

bool Board::IsGameLoss(char player) {
	return false;
}

bool Board::IsBoardFull() {
	return false;
}

void Board::RefreshScreen() {
	this->ClearTerminal();
	this->CreateHeader();
	this->PrintBoard();
}

void Board::UpdateMove() {
	std::pair<int, int> playerMove = this->GetPlayerMove();
	if (this->IsLegalMove(playerMove.first, playerMove.second)) {
		this->PlayerMakeMove(playerMove.first, playerMove.second);
		this->RefreshScreen();
	}
	else {
		this->RefreshScreen();
		cout << "Postion: " << playerMove.first << "," << playerMove.second << " is not a legal move." << endl;
		this->UpdateMove();
	}
}

bool Board::IsLegalMove(int row, int col) {
	if (this->board[row][col] == BLANK_MARKER) {
		return true;
	}
	return false;
}

std::pair<int, int> Board::GetPlayerMove() {
	int row, col;
	cout << "Row position: ";
	cin >> row;
	cout << "Col play: ";
	cin >> col;
	cout << endl << endl;

	return std::make_pair(row, col);
}

void Board::PlayerMakeMove(int row, int col) {
	this->board[row][col] = PLAYER_MARKER;
	this->occupiedPosition[row][col] = PLAYER_MARKER;
}

void Board::AIMakeMove() {
	// Check Player positions to block winning positions

	// Make move to win
}

bool Board::IsPositionOccupied(std::pair<int, int> pos) {
	return false;
}

void Board::ClearTerminal() {
	// Clearing the terminal
	#ifdef _WIN32
		system("cls"); // For Windows
	#else
		system("clear"); // For Unix/Linux
	#endif
}