#pragma once
#include "general.h"

class Piece
{
protected:
	bool _color;
	int _row;
	int _col;
	char _symbol;
	bool _hasMoved;

public:
	Piece(int row, int col, bool color, int symbol);
	virtual bool canMove(int row, int col, Piece*** board) = 0;
	char getSymbol() const;
	bool getColor() const;
	void setRow(int row);
	void setCol(int col);

	void markMoved();
	bool isDiagonalEmpty(int row, int col, Piece*** board);
	bool isSidesEmpty(int row, int col, Piece*** board);
};