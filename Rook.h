#pragma once
#include "Piece.h"
#include "general.h"

class Rook : public Piece
{
public:
	Rook(int row, int col, bool color, int symbol);
	virtual bool canMove(int row, int col, Piece*** board);
};