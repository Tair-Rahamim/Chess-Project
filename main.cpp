#include "GameBoard.h"
#include <stdio.h>

//if you want to run the game through the console, change this function to main() and the "main" in source.cpp to something else...
int mainxx()
{
	GameBoard board;
	
	char srcColChr = 0, dstColChr = 0;
	int srcRow = 0, srcCol = 0, dstRow = 0, dstCol = 0;
	int moveCode = 0;
	char* boardStr = nullptr;

	while (moveCode != 8) { // 8 = check mate
		board.print();
		std::cout << "playing: " << ((board.getPlayer() == WHITE) ? "white" : "black") << std::endl;
		std::cout << "Enter source row, col: " << std::endl;
		std::cin >> srcRow;
		std::cin >> srcColChr;
		srcCol = GameBoard::getColumnIndex(srcColChr);
		std::cout << "Enter destination row, col: " << std::endl;
		std::cin >> dstRow;
		std::cin >> dstColChr;
		dstCol = GameBoard::getColumnIndex(dstColChr);
		moveCode = board.play(--srcRow, --srcCol, --dstRow, --dstCol);
		std::cout << "returned code: " << moveCode << std::endl;
		std::cout << "------------------------" << std::endl;
	}

	return 0;
}