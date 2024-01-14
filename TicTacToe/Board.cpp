#include "Board.h"

Board::Board() {}

Board::~Board() {}

void Board::CreateHeader() {
	cout << "Tic Tac Toe \n\n" << endl << endl;
	cout << "Player = X\t AI Computer = O" << endl << endl;
}

void Board::CreateBoard() {
	cout << endl;
	cout << this->board[0][0] << " | " << this->board[0][1] << " | " << this->board[0][2] << endl;
	cout << endl;
	cout << this->board[1][0] << " | " << this->board[1][1] << " | " << this->board[1][2] << endl;
	cout << endl;
	cout << this->board[2][0] << " | " << this->board[2][1] << " | " << this->board[2][2] << endl;
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
}

bool Board::IsGameWon() {

}

bool Board::IsGameLoss() {

}

bool Board::IsBoardFull() {

}

void Board::UpdateMove() {

}

std::vector<std::pair<int, int>> Board::GetLegalMoves()
{

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

bool Board::IsPositionOccupied(std::pair<int, int> pos) {

}
