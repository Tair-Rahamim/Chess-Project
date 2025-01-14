#pragma once
#include "Piece.h"
#include "general.h"

class Queen : public Piece
{
public:
	Queen(int row, int col, bool color, int symbol);
	virtual bool canMove(int row, int col, Piece*** board);
};