/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class header file for the TicTacToe class. It contains a Board object to create
** a board to play on. It also has a string value that keeps track of the current turn. It has a constructor
** that asks for and sets the starting player, X or O. Ii also has a function called play that plays the game.
********************************************************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"
#include <string>
class TicTacToe
{
private:
	Board brd;
	string curTurn;
public:
	TicTacToe(char);
	void play();
	
};

#endif