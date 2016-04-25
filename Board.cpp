/*******************************************************************************************************
** Author: Joseph Fuerst
** Date: 3/3/2016
** Description: This is the class implementation file for the Board class. It includes a default constructor 
that makes an "empty" array. It also has a function called makeMove that inputs the users coordinates to
** make a move. It returns false if the move is invalid. THe gameState function returns the enum value for
** State, to check for a winner. THe print function prints out the game board.
********************************************************************************************************/

#include "Board.hpp"
#include <iostream>

using std::cout;
using std::endl;

/***************************************************************************************************************
*						Board::Board
* This constructor initializes the board array to contain all "."
****************************************************************************************************************/
Board::Board()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = ".";
}
/***************************************************************************************************************
*						Board::makeMove
* This function takes the two ints representing the row and column, and places the value of the current player in
* the appropriate array location.
****************************************************************************************************************/
bool Board::makeMove(int row, int column, string player)
{
	if (board[row][column] == ".") //checks for valid move.
	{
		board[row][column] = player;
		return true;
	}
	else //invalid move
		return false;
}
/***************************************************************************************************************
*						Board::gameState
* This function updates and returns the gamestate. It tests each of the possible win scenarios each move, and 
*changes the State value accordingly. If there is no winner and the board is full, it indicates a draw, otherwise
* it iindicates that the game is still in progress.
****************************************************************************************************************/
State Board::gameState()
{
	if (board[0][0] != "." && board[0][0] == board[0][1] && board[0][1] == board[0][2]) //top row win
	{
		if (board[0][0] == "X")
		{
			return X_WIN;
		}
		else if (board[0][0] == "O")
		{
			return O_WIN;
		}
	}
	else if (board[1][0] != "." && board[1][0] == board[1][1] && board[1][1] == board[1][2]) //middle row win
	{
		if (board[1][0] == "X")
		{
			return X_WIN;
		}
		else if (board[1][0] == "O")
		{
			return O_WIN;
		}
	}
	else if (board[2][0] != "." && board[2][0] == board[2][1] && board[2][1] == board[2][2]) // bottom row win
	{
		if (board[2][0] == "X")
		{
			return X_WIN;
		}
		else if (board[2][0] == "O")
		{
			return O_WIN;
		}
	}
	else if (board[0][0] != "." && board[0][0] == board[1][0] && board[1][0] == board[2][0]) //left column win
	{
		if (board[0][0] == "X")
		{
			return X_WIN;
		}
		else if (board[0][0] == "O")
		{
			return O_WIN;
		}
	}
	else if (board[0][1] != "." && board[0][1] == board[1][1] && board[1][1] == board[2][1]) //middle column win
	{
		if (board[0][1] == "X")
		{
			return X_WIN;
		}
		else if (board[0][1] == "O")
		{
			return O_WIN;
		}
	}
	else if (board[0][2] != "." && board[0][2] == board[1][2] && board[1][2] == board[2][2]) //right column win
	{
		if (board[0][2] == "X")
		{
			return X_WIN;
		}
		else if (board[0][2] == "O")
		{
			return O_WIN;
		}
	}
	else if (board[0][0] != "." && board[0][0] == board[1][1] && board[1][1] == board[2][2])// diagonal \ win
	{
		if (board[0][0] == "X")
		{
			return X_WIN;
		}
		else if (board[0][0] == "O")
		{
			return O_WIN;
		}
	}
	else if (board[2][0] != "." && board[2][0] == board[1][1] && board[1][1] == board[0][2]) // diagonal / win
	{
		if (board[2][0] == "X")
		{
			return X_WIN;
		}
		else if (board[2][0] == "O")
		{
			return O_WIN;
		}
	}
	else //no winner yet
	{
		bool isOver = true;
		for (int i = 0; i < 3; i++) //checks for empty spaces
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ".")
					isOver = false; //if there are empty spaces, isOver is false
			}
		}
		if (isOver == false)
			return IN_PROGRESS;
		else if (isOver == true) //no moves remaining
			return DRAW;
	}
}
/***************************************************************************************************************
*						Board::print
* This function prints out a basic visualization of the board. 
****************************************************************************************************************/
void Board::print()
{
	cout << "  " << "0 1 2" << endl; //The 0 1 2 on the top and side are for reference.
	cout << "0 " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl; //first row
	cout << "1 " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl; //second row
	cout << "2 " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl; //third row
	/*****************************************
	* Prints like this initially
	*   0 1 2
	* 0 . . .
	* 1 . . .
	* 2 . . .
	* dots update to X or O depending on move
	*****************************************/
}

