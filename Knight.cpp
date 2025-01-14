#include "knight.h"

// if this functions returns false, it means error code 6
bool Knight::canMove(int row, int col, Piece*** board)
{
	if ((row == this->_row - 1 && col == this->_col - 2)||
		(row == this->_row - 2 && col == this->_col - 1)||
		(row == this->_row - 2 && col == this->_col + 1)||
		(row == this->_row - 1 && col == this->_col + 2)||
		(row == this->_row + 1 && col == this->_col + 2)||
		(row == this->_row + 2 && col == this->_col + 1)||
		(row == this->_row + 2 && col == this->_col - 1)||
		(row == this->_row + 1 && col == this->_col - 2))
		return true;
	return false;
}

Knight::Knight(int row, int col, bool color, int symbol) :
	Piece(row, col, color, symbol)
{
}
