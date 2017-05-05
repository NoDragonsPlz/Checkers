* Nicolas Wilhoit
   Max Anaya
   Mark Ortega
   The following code is for our multiplayer checkers program*/

#include <iostream>
#include <time.h>
#include <ctype.h>
using namespace std;
class Board
{
public:
	~Board() {};
	Board();
	void printb();
	void player1_move();
	void player2_move();
	void instructions();
	void setpieces();
	int checkwin();

private:
	char cboard[9][9];

};
Board::Board()
{
	char w = 177;
	int row, column, side = 0, top = 0;
	cout << "Initializing the Checkers Board........" << endl;
	cout << "    0  1  2  3  4  5  6  7 " << endl;
	cout << "----------------------------" << endl;
	for (row = 0; row<8; row++)
	{
		cout << side << " |";
		++side;

		for (column = 0; column<8; column++)
			if ((row + column) % 2 == 0)
				cboard[row][column] = w;
			else
				cboard[row][column] = 0;
		cout << "|" << endl;
	}
	cout << "----------------------------" << endl;
}
void Board::setpieces()
{
	int row = 0, column = 0;
	for (row = 1; row <= 8; row++)
		for (column = 1; column <= 8; column++)
		{
			if ((row + column) % 2 == 0 && row <= 3)
				cboard[row][column] = 'h';
			else if ((row + column) % 2 == 0 && row>2 && row <= 5)
				cboard[row][column] = 177;
			else if ((row + column) % 2 == 0 && row>5 && row <= 8)
				cboard[row][column] = 'q';
			else
				cboard[row][column] = 0;
		}
}
int Board::checkwin()
{
	int i, j;
	for (i = 1; i <= 8; ++i)
		for (j = 1; j <= 8; ++j)
		{
			if (cboard[i][j] == 'h' || cboard[i][j] == 'q')
			{
				cout << "Continue playing....." << endl;
				return (1);
			}
			else if (cboard[i][j] != 'h')
			{
				cout << "PLAYER 2 WINS!!!" << endl;
				return(0);
			}
			else if (cboard[i][j] != 'q')
			{
				cout << "PLAYER 1 WINS!!!!" << endl;
				return(0);
			}
		}
}
void Board::player2_move()
{
	int oldrow = 1, oldcolumn = 1, row = 1, column = 1;
	char w = 177, h = 104;
	do
	{
		cout << "Enter the row of the piece you would like to move from: " << endl;
		cin >> oldrow;
		cout << "Enter the column of the piece you would like to move from: " << endl;
		cin >> oldcolumn;
		cout << "Enter the new row you would like to move the piece to: " << endl;
		cin >> row;
		cout << "Enter the new column you would like to move the piece to: " << endl;
		cin >> column;
		if (cboard[row][column] == 0)
		{
			cout << "INVALID MOVE" << endl;
			oldrow = 0;
		}
		if (oldrow >= 1 && oldcolumn >= 1)
		{
			if (cboard[oldrow][oldcolumn] != 'q')
			{
				cout << "INVALID MOVE" << endl;
				oldrow = 0;
			}
			else if (cboard[oldrow][oldcolumn] == 'q')
			{
				cout << "Hello1" << endl;
				cboard[oldrow][oldcolumn] = 177;
				cboard[row - 1][column - 1] = 177;
				cboard[row][column] = 'q';
			}
			else if (cboard[row - 1][column - 1] == 'q')
			{
				cout << "HELLO AGAIN" << endl;
				cboard[oldrow][oldcolumn] = 177;
				cboard[row - 1][column - 1] = 177;
				cboard[row][column] = 'q';
			}
			else
			{
				cout << "INVALID MOVE 2" << endl;
			}
		}
		cout << "Player 2 moves from row: " << oldrow << endl;
		cout << "Player 2 moves from column: " << oldcolumn << endl;
		cout << "To row: " << row << endl;
		cout << "To column: " << column << endl;

	} while (oldrow<1 || oldcolumn<1 || row<1 || column<1 || oldrow>8 || oldcolumn>8 || row>8 || column>8);
}

void Board::instructions()
{
	int i = 0;
	char s = 4;
	for (i = 0; i <= 53; ++i)
	{
		cout << s;
	}
	cout << endl << s << "  THESE ARE THE INSTRUCTION FOR CHECKERS!           " << s << endl;
	cout << s << "  1) Player 2 is represented by a 'q'           " << s << endl;
	cout << s << "  2) Player 1 is represented by a 'h'              " << s << endl;
	cout << s << "  3) When a piece is kinged it will be capitalized  " << s << endl;
	cout << s << "  4) When a piece is kinged it may move backwards   " << s << endl;
	cout << s << "  5) Player 1 will move first each time         " << s << endl;
	for (i = 0; i <= 53; ++i)
	{
		cout << s;
	}
	cout << endl;
}
void Board::printb()
{
	char w = 177;
	int row, column;
	cout << "    1  2  3  4  5  6  7  8" << endl;
	cout << "----------------------------" << endl;
	for (row = 1; row <= 8; row++)
	{
		cout << row << " |";
		for (column = 1; column <= 8; column++)
			if ((row + column) % 2 == 0)
				cout << w << cboard[row][column] << w;
			else
				cout << " " << cboard[row][column] << " ";
		cout << "|" << endl;

	}
	cout << "----------------------------" << endl;
}
void Board::player1_move()
{
	int oldrow = 1, oldcolumn = 1, row = 1, column = 1;
	char w = 177, h = 104;
	do
	{
		cout << "Enter the row of the piece you would like to move from: " << endl;
		cin >> oldrow;
		cout << "Enter the column of the piece you would like to move from: " << endl;
		cin >> oldcolumn;
		cout << "Enter the new row you would like to move the piece to: " << endl;
		cin >> row;
		cout << "Enter the new column you would like to move the piece to: " << endl;
		cin >> column;
		if (cboard[row][column] == 0)
		{
			cout << "INVALID MOVE" << endl;
			oldrow = 0;
		}
		if (oldrow >= 1 && oldcolumn >= 1)
		{
			if (cboard[oldrow][oldcolumn] != 'h')
			{
				cout << "INVALID MOVE" << endl;
				oldrow = 0;
			}
			else if (cboard[oldrow][oldcolumn] == 'h')
			{
				cout << "Hello1" << endl;
				cboard[oldrow][oldcolumn] = 177;
				cboard[row - 1][column - 1] = 177;
				cboard[row][column] = 'h';
			}
			else if (cboard[row - 1][column - 1] == 'q')
			{
				cout << "HELLO AGAIN" << endl;
				cboard[oldrow][oldcolumn] = 177;
				cboard[row - 1][column - 1] = 177;
				cboard[row][column] = 'h';
			}
			else
			{
				cout << "INVALID MOVE 2" << endl;
			}
		}
		cout << "Player 1 moves from row: " << oldrow << endl;
		cout << "Player 1 moves from column: " << oldcolumn << endl;
		cout << "To row: " << row << endl;
		cout << "To column: " << column << endl;

	} while (oldrow<1 || oldcolumn<1 || row<1 || column<1 || oldrow>8 || oldcolumn>8 || row>8 || column>8);
}
void main()
{
	srand(time(0));
	int i = 0, m = 0;
	Board play_game;
	play_game.instructions();
	play_game.setpieces();
	play_game.printb();
	do
	{
		play_game.printb();
		++i;
		play_game.player1_move();
		m = play_game.checkwin();
		play_game.printb();
		play_game.player2_move();
		m = play_game.checkwin();
		++i;
	} while (i<500);
}

