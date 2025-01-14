#include "Piece.h"

Piece::Piece(int row, int col, bool color, int symbol)
{
	this->_row = row;
	this->_col = col;
	this->_color = color;
	this->_symbol = symbol;
	this->_hasMoved = false;
}

char Piece::getSymbol() const
{
	return this->_symbol;
}

bool Piece::getColor() const
{
	return this->_color;
}

void Piece::setRow(int row)
{
	this->_row = row;
}

void Piece::setCol(int col)
{
	this->_col = col;
}

//check if a two squares are diagonal to each other, and the path from one to another is empty
bool Piece::isDiagonalEmpty(int dstRow, int dstCol, Piece*** board)
{
	//check the main diagonal
	if (this->_row - this->_col == dstRow - dstCol)
	{
		if (this->_col < dstCol)
		{
			for (int i = 1; i < dstRow - this->_row; i++)
				if (board[this->_row + i][this->_col + i] != EMPTY)
					return false;
			return true;
		}
		else if (this->_col > dstCol)
		{
			for (int i = 1; i < this->_row - dstRow; i++)
				if (board[this->_row - i][this->_col - i] != EMPTY)
					return false;
			return true;
		}
	}
	//check the secondary diagonal
	else if (this->_row + this->_col == dstRow + dstCol)
	{
		if (this->_col < dstCol)
		{
			for (int i = 1; i < dstRow - this->_row; i++)
				if (board[this->_row - i][this->_col + i] != EMPTY)
					return false;
			return true;
		}
		else if (this->_col > dstCol)
		{
			for (int i = 1; i < this->_row - dstRow; i++)
				if (board[this->_row + i][this->_col - i] != EMPTY)
					return false;
			return true;
		}
	}
	return false;
}

//check if a two squares are horizntal/vertical to each other, and the path from one to another is empty
bool Piece::isSidesEmpty(int row, int col, Piece*** board)
{
	const bool ERR6 = false; // invalid piece move, code 6
	if (this->_row != row && this->_col != col)
		return ERR6;
	//check vertical
	if (this->_row == row)
	{
		if (this->_col < col)
		{
			for (int i = this->_col + 1; i < col - 1; i++)
				if (board[row][i] != EMPTY)
					return ERR6;
			return true;
		}

		else if (this->_col > col)
		{
			for (int i = this->_col - 1; i < col + 1; i--)
				if (board[row][i] != EMPTY)
					return ERR6;
			return true;
		}
	}
	//check horizontal
	else if (this->_col == col)
	{
		if (this->_row < row)
		{
			for (int i = this->_row + 1; i < row - 1; i++)
				if (board[i][col] != EMPTY)
					return ERR6;
			return true;
		}

		else if (this->_row > row)
		{
			for (int i = this->_row - 1; i > row + 1; i--)
				if (board[i][col] != EMPTY)
					return ERR6;
			return true;
		}
	}
	else return false;
}

void Piece::markMoved()
{
	this->_hasMoved = true;
}