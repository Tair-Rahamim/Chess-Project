#pragma once
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "general.h"
#include <string>
#include <cctype>
#include <iostream>

class GameBoard
{
private:
	bool _player;
	Piece*** _board;
	King* whiteKing;
	King* blackKing;

public:
	GameBoard();
	~GameBoard();
	void print() const;
	int play(int srcRow, int srcCol, int dstRow, int dstCol);
	bool move(int srcRow, int srcCol, int dstRow, int dstCol, bool checkIfChess);
	void switchPlayer();
	static int getColumnIndex(char col);
	char* toString() const;
	bool getPlayer() const;
};