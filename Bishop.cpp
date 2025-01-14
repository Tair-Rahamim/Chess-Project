#include "Bishop.h"

// if this functions returns false, it means error code 6
bool Bishop::canMove(int row, int col, Piece*** board)
{
	return isDiagonalEmpty(row, col, board);
}

Bishop::Bishop(int row, int col, bool color, int symbol):
	Piece(row, col, color, symbol)
{
}
