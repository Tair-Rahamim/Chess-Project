#include "King.h"

King::King(int row, int col, bool color, int symbol) :
	Piece(row, col, color, symbol)
{
}

bool King::canMove(int row, int col, Piece*** board)
{
	if ((row == this->_row || row == this->_row + 1 || row == this->_row - 1) &&
		(col == this->_col || col == this->_col + 1 || col == this->_col - 1))
		return true;
	return false;
}

bool King::isThreatend(Piece*** board) const
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (board[i][j] != EMPTY && board[i][j]->getColor() != this->_color)
				if (!(i == this->_row && j == this->_col) &&
					board[i][j]->canMove(this->_row, this->_col, board))
					return true;
	return false;
}