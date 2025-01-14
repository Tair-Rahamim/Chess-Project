#include "Queen.h"

// if this functions returns false, it means error code 6
bool Queen::canMove(int row, int col, Piece*** board)
{
	return isSidesEmpty(row, col, board) || isDiagonalEmpty(row, col, board);
}

Queen::Queen(int row, int col, bool color, int symbol) :
	Piece(row, col, color, symbol)
{
}
