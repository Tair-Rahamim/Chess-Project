/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "GameBoard.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::string;


int main()
{
	srand(time_t(NULL));


	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return 0;
		}
	}


	char msgToGraphics[1024];

	GameBoard board;
	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		//interpert the message
		char srcColChr = msgFromGraphics[0], dstColChr = msgFromGraphics[2];
		int srcRow = 0, srcCol = 0, dstRow = 0, dstCol = 0;
		srcRow = msgFromGraphics[1] - '1';
		dstRow = msgFromGraphics[3] - '1';
		srcCol = GameBoard::getColumnIndex(srcColChr) - 1;
		dstCol = GameBoard::getColumnIndex(dstColChr) - 1;


		//make the move
		int moveCode = board.play(srcRow, srcCol, dstRow, dstCol);
		msgToGraphics[0] = moveCode + '0';
		msgToGraphics[1] = 0;
		// msgToGraphics should contain the result of the operation

		/******* JUST FOR EREZ DEBUGGING ******/
		/*
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		*/
		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}