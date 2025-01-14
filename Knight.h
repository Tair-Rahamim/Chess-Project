#pragma once
#include "Piece.h"
#include "general.h"

class Knight : public Piece
{
public:
	Knight(int row, int col, bool color, int symbol);
	virtual bool canMove(int row, int col, Piece*** board);
};