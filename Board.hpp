/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class header file for the Board class. It contains an enum called State
** that has 4 values, to keep track of the gamestate. It has a 2d array to be the "board" that the game is 
** played on. It includes a default constructor that makes an "empty" array. It also has a function called 
** makeMove that inputs the users coordinates to make a move. It returns false if the move is invalid.
** THe gameState function returns the enum value for State, to check for a winner. THe print function prints
** out the game board.
********************************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

using std::string;

enum State {X_WIN, O_WIN, DRAW, IN_PROGRESS};

class Board
{
private:
	string board[3][3];
	

public:
	Board();
	bool makeMove(int, int, string);
	State gameState();
	void print();

};

#endif