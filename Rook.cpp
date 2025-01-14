#include "Rook.h"

// if this functions returns false, it means error code 6
bool Rook::canMove(int row, int col, Piece*** board)
{
	return isSidesEmpty(row, col, board);
}

Rook::Rook(int row, int col, bool color, int symbol) :
	Piece(row, col, color ,symbol)
{
}
