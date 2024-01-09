#include "Board.h"

Board::Board() {}

void Board::CreateHeader() {
	cout << "Tic Tac Toe \n\n" << endl << endl;
	cout << "Player = X\t AI Computer = O" << endl << endl;
}

void Board::CreateBoard() {
	cout << endl;
	cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << endl;
	cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << endl;
	cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void Board::Run() {

}