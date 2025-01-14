#include "GameBoard.h"

GameBoard::GameBoard()
{
	this->blackKing = EMPTY;
	this->whiteKing = EMPTY;

	this->_board = new Piece**[SIZE];
	this->_player = WHITE;
	std::string baseStr = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR";
	for (int i = 0; i < SIZE; i++)
	{
		this->_board[i] = new Piece * [SIZE];
		for (int j = 0; j < SIZE; j++)
		{
			this->_board[i][j] = EMPTY;
			int index = i * SIZE + j;
			char ch = baseStr[index];
			bool color = BLACK;
			if (isupper(ch)) color = WHITE;
			//Piece* piece = new Piece(i, j, color, ch);
			switch (tolower(ch))
			{
			case 'r': // rook
				this->_board[i][j] = new Rook(i, j, color, ch);
				break;
			case 'n':  // knight
				this->_board[i][j] = new Knight(i, j, color, ch);
				break;
			case 'b': // bishop
				this->_board[i][j] = new Bishop(i, j, color, ch);
				break;
			case 'k': // king
				this->_board[i][j] = EMPTY;
				if (color == WHITE) {
					this->whiteKing = new King(i, j, color, ch);
					this->_board[i][j] = this->whiteKing;
				}
				else // if black
				{
					this->blackKing = new King(i, j, color, ch);
					this->_board[i][j] = this->blackKing;
				}
				break;
			case 'q': // queen
				this->_board[i][j] = new Queen(i, j, color, ch);
				break;
			case 'p': // pawn
				this->_board[i][j] = new Pawn(i, j, color, ch);
				break;
			case '#': // empty
				this->_board[i][j] = EMPTY;
				break;
			default:
				std::cout << "How the hell did you managed to reach here you &@Y#*@!." << std::endl;
				break;
			}
		};
	}
	
}

GameBoard::~GameBoard()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (this->_board[i][j] != EMPTY)
				delete this->_board[i][j];
	delete this->_board;
}

void GameBoard::print() const
{
	std::cout << "    a b c d e f g h" << std::endl;
	std::cout << "  /-----------------" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << 8 - i << " | ";
		for (int j = 0; j < SIZE; j++)
		{
			char ch = 0;
			if (this->_board[i][j] == EMPTY)
				ch = '#';
			else
				ch = this->_board[i][j]->getSymbol();
			std::cout << ch << " ";
		}
		std::cout << std::endl;
	}
}

// the function moves a piece to a given destination
// if the move caused "check" on yourself, returns false and doesn't make the move
// if the move didn't cause "check" on yourself, it updates the board and returns true
// note: the function assumes that the move is legal
// checkIfCheck - should the function check if you caused chess on yourself or just move?
bool GameBoard::move(int srcRow, int srcCol, int dstRow, int dstCol, bool checkIfCheck = true)
{
	// make the move
	Piece* deleted = this->_board[dstRow][dstCol];
	this->_board[dstRow][dstCol] = this->_board[srcRow][srcCol];
	this->_board[srcRow][srcCol] = EMPTY;
	this->_board[dstRow][dstCol]->setRow(dstRow);
	this->_board[dstRow][dstCol]->setCol(dstCol);

	if (checkIfCheck) {
		// check if the move caused check on yourself
		if ((this->_player == WHITE && this->whiteKing->isThreatend(this->_board)) ||
			(this->_player == BLACK && this->blackKing->isThreatend(this->_board))) {
			// if yes, undo the changes
			this->_board[srcRow][srcCol] = this->_board[dstRow][dstCol];
			this->_board[dstRow][dstCol] = deleted;
			// restore the moved piece properties
			this->_board[srcRow][srcCol]->setRow(srcRow);
			this->_board[srcRow][srcCol]->setCol(srcCol);

			return false;
		}
	}
	delete deleted;
	return true;
}

void GameBoard::switchPlayer()
{
	if (this->_player == WHITE)
		this->_player = BLACK;
	else if (this->_player == BLACK)
		this->_player = WHITE;
}

bool GameBoard::getPlayer() const
{
	return this->_player;
}

char* GameBoard::toString() const
{
	char* str = new char[SIZE * SIZE + 2];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (this->_board[i][j] == EMPTY)
				str[i * SIZE + j] = '#';
			else // not empty
				str[i * SIZE + j] = this->_board[i][j]->getSymbol();
		}
	}
	str[SIZE * SIZE] = (this->_player == WHITE) ? '0' : '1';
	str[SIZE * SIZE + 1] = NULL;
	return str;
}

int GameBoard::play(int srcRow, int srcCol, int dstRow, int dstCol)
{
	//first, make the rows indexes to array indexes(since they are reversed)
	srcRow = 7 - srcRow;
	dstRow = 7 - dstRow;


	if ((srcRow == dstRow) && (srcCol == dstCol))
		return 7;
	if (!(0 <= srcRow && srcRow <= 7) ||
		!(0 <= srcCol && srcCol <= 7) ||
		!(0 <= dstRow && dstRow <= 7) ||
		!(0 <= dstCol && dstCol <= 7))
		return 5;
	if (this->_board[srcRow][srcCol] == EMPTY ||
		this->_board[srcRow][srcCol]->getColor() != this->_player)
		return 2;
	if (this->_board[dstRow][dstCol] != EMPTY &&
		this->_board[dstRow][dstCol]->getColor() == this->_board[srcRow][srcCol]->getColor())
		return 3;

	if (this->_board[srcRow][srcCol]->canMove(dstRow, dstCol, this->_board))
	{
		//check if the move will lead to your win, if so, return 8
		if (this->_board[dstRow][dstCol] != EMPTY &&
			((this->_player == WHITE && this->_board[dstRow][dstCol]->getSymbol() == 'k') ||
			(this->_player == BLACK && this->_board[dstRow][dstCol]->getSymbol() == 'K'))) {
			move(srcRow, srcCol, dstRow, dstCol, false);
			switchPlayer();
			return 8;
		}
		//make the move
		//check if the move caused "check" on yourself, if so, return 4 and cancel the move
		if (!move(srcRow, srcCol, dstRow, dstCol))
			return 4;

		this->_board[dstRow][dstCol]->markMoved();
		//check if the move caused "check" on your oponent, if so, return 1
		if ((this->_player == WHITE && this->blackKing->isThreatend(this->_board)) ||
			(this->_player == BLACK && this->whiteKing->isThreatend(this->_board))) {
			switchPlayer();
			return 1;
		}
		//else - move is valid
		switchPlayer();
		return 0;
	} else return 6;
}

//the column indexes are listed as 'a'-'h'
//this turns them into number indexes (1-8)
int GameBoard::getColumnIndex(char col)
{
	return col - 'a' + 1;
}