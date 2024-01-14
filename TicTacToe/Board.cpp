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
/*
	for (const auto& vectorOfPairs : this->winning_moves) {
		for (const auto& pair : vectorOfPairs) {
			cout << pair.first << "," << pair.second << " ";
		}
		cout << endl;
	}
*/
	std::pair<int, int> playerMove = this->GetPlayerMove();
	this->board[playerMove.first][playerMove.second] = PLAYER_MARKER;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << this->board[i][j] << ' ';
		}
		cout << endl;
	}

}

void Board::Run() {
	this->CreateHeader();
	this->CreateBoard();
	this->BeginGame();
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
	return false;
}

std::pair<int,bool> Board::CheckGameState() {
	if (this->IsGameWon()) {
		return std::make_pair(WIN, true);
	}
	if (this->IsGameLoss()) {
		return std::make_pair(LOSS, true);
	}
	if (this->IsBoardFull()) {
		return std::make_pair(DRAW,true);
	}
	return std::make_pair(INPROGESS, false);
}

bool Board::IsGameWon() {

	return false;
}

bool Board::IsGameLoss() {
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
}

void Board::AIMakeMove() {

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