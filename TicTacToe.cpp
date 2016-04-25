/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class implementation file for the TicTacToe class.  It has a constructor
** that asks for and sets the starting player, X or O. Ii also has a function called play that plays the game.
** it also includes the main method to set up and play the game. 
********************************************************************************************************/

#include "TicTacToe.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
/***************************************************************************************************************
*						TicTacToe::TicTacToe
* This constructor takes a char argument and sets curTurn equal to either X or O. If the argument is not x or o 
* it sets the default starter to x.
****************************************************************************************************************/
TicTacToe::TicTacToe(char plr)
{
	if (plr == 'x' || plr == 'X') //checks for upper and lower case
		curTurn = "X"; 
	else if (plr == 'o' || plr == 'O')
		curTurn = "O";
	else
	{
		cout << "Not a valid input. Default starter will be X" << endl;
		curTurn = "X";
	}
}
/***************************************************************************************************************
*						TicTacToe::play
* This function plays the game. It records a players move and gets an updated gamestate each loop until gamestate 
* indicates either a win or a draw.
****************************************************************************************************************/
void TicTacToe::play()
{
	int firstCoord, secondCoord;
	bool goodMove;
	State result = brd.gameState();
	
	while (result == IN_PROGRESS)
	{
		brd.print();
		cout << "Player " << curTurn << ": Please enter your move." << endl;
		cout << "Enter the row first(0-2): " << endl;
		cin >> firstCoord;
		cout << "Now enter the column(0-2)" << endl;
		cin >> secondCoord;
		goodMove = brd.makeMove(firstCoord, secondCoord, curTurn); //makes the move and returns a bool value
		if (goodMove == false) //indicates an invalid move, and goes to the top of the while loop.
		{
			cout << "That square is already taken." << endl;
		}
		else
		{
			result = brd.gameState(); //update gamestate
			if (curTurn == "X") //changes curTurn to next player
				curTurn = "O";
			else if (curTurn == "O")
				curTurn = "X";
		}
	}
	//Once while loop exits, it checks the end gameState, it will be one of the following possible outcomes.
	if (result == X_WIN)
	{
		cout << "Player X has won!" << endl;
		brd.print();
	}
	else if (result == O_WIN)
	{
		cout << "Player O has won!" << endl;
		brd.print();
	}
	else if (result == DRAW)
	{
		cout << "It is a draw" << endl;
		brd.print();
	}

}

int main()
{
	string pChoice;
	cout << "Which player will go first? X or O:" << endl;
	cin >> pChoice; //enter x, X, o, or O to choose which player goes first
	char choice = pChoice[0]; //convert to char for constructor
	TicTacToe game1(choice);//create game and board
	game1.play(); //play the game

	return 0;
}
