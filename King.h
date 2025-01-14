#pragma once
#include "Piece.h"
#include "general.h"

class King : public Piece
{
public:
	King(int row, int col, bool color, int symbol);
	bool canMove(int row, int col, Piece*** board);
	bool isThreatend(Piece*** board) const;
};