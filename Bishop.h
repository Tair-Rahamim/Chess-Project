#pragma once
#include "Piece.h"
#include "general.h"

class Bishop : public Piece
{
public:
	Bishop(int row, int col, bool color, int symbol);
	virtual bool canMove(int row, int col, Piece*** board);
};