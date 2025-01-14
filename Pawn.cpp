#include "Pawn.h"

// if this functions returns false, it means error code 6
bool Pawn::canMove(int row, int col, Piece*** board)
{
	// the pawn is just moving
	if (board[row][col] == EMPTY) {
		if ((this->_color == WHITE && this->_row - 1 == row) ||
			(this->_color == BLACK && this->_row + 1 == row))
			return true;
		else if (this->_hasMoved == false)
			if ((this->_color == WHITE && this->_row - 2 == row) ||
				(this->_color == BLACK && this->_row + 2 == row))
				return true;
	}
	else // if the pawn is attacking another piece
	{
		if (this->_col == col + 1 || this->_col == col -1) {
			if ((this->_color == WHITE && this->_row - 1 == row) ||
				(this->_color == BLACK && this->_row + 1 == row))
				return true;
		}
	}
	return false;
}

Pawn::Pawn(int row, int col, bool color, int symbol) :
	Piece(row, col, color, symbol)
{
}
