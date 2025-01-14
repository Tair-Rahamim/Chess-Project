#pragma once
#include "Piece.h"
#include "general.h"

class Pawn : public Piece
{
public:
	Pawn(int row, int col, bool color, int symbol);
	virtual bool canMove(int row, int col, Piece*** board);
};