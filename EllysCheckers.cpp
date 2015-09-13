// BEGIN CUT HERE
// PROBLEM STATEMENT
// Elly and Kriss play a game. The game is played on a single row that consists 
// of N cells; we will call it the board. The cells of the board are numbered 0 
// through N-1, from the left to the right. Each cell of the board is either 
// empty or occupied by a single checker. The girls take alternating turns, until 
// one of them cannot make a move. The girl who is unable to make a move loses 
// the game.
// 
// In each move the current player selects a cell containing a checker and 
// performs one of the following two types of moves:
// 
// A step, in which the checker is moved one cell to the right. The step can only 
// be made if the target cell is empty.
// A jump, in which the checker jumps three cells to the right. The jump can only 
// be made if the target cell is empty and the cells it jumped over contain two 
// other checkers.
// 
// Once a checker reaches the rightmost cell, it disappears immediately and no 
// longer plays any role in the game.
// 
// The initial layout of the board will be given as a string board. The i-th 
// character of board will be '.' (a period) if the i-th cell is empty at the
// beginning, and it will be 'o' (lowercase letter o) if the i-th cell initially 
// contains a checker. Assume that both girls play optimally. Return "YES" 
// (quotes for clarity) if the first player wins the game and "NO" otherwise.
// 
// DEFINITION
// Class:EllysCheckers
// Method:getWinner
// Parameters:string
// Returns:string
// Method signature:string getWinner(string board)
// 
// 
// NOTES
// -If there is a checker on the rightmost cell in the beginning of the game, it 
// disappears instantly (before the first move is made), as if it were never there.
// -The rules of the game ensure that each cell contains at most one checker at 
// any time, and that no checker can jump beyond the last cell.
// 
// 
// CONSTRAINTS
// -board will contain between 1 and 20 characters, inclusive.
// -Each character of board will be either '.' or 'o'.
// 
// 
// EXAMPLES
// 
// 0)
// ".o..."
// 
// Returns: "YES"
// 
// With only one checker it is pretty obvious who will win.
// 
// 1)
// "..o..o"
// 
// Returns: "YES"
// 
// Don't forget to ignore checkers on the rightmost cell.
// 
// 2)
// ".o...ooo..oo.."
// 
// Returns: "NO"
// 
// Here one can jump the checker from cell 5 to cell 8.
// 
// 3)
// "......o.ooo.o......"
// 
// Returns: "YES"
// 
// 4)
// ".o..o...o....o.....o"
// 
// Returns: "NO"
// 
// END CUT HERE
#line 83 "EllysCheckers.cpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> 
#include <map> 
#include <queue> 
#include <stack> 

using namespace std; 

class EllysCheckers {
	public:
	string getWinner(string board) 
	{
		int m = 0;  
		while (moveBoard(board) != board) {
			m++; 
			//board = moveBoard(board); 
		}

		if (m % 2 == 0) return "NO";
		else return "YES"; 
	}

	private:
	bool moreMove(string board) {
		for (int i = 0; i < board.length() - 1; i++) {
			if (board[i] == 'o') {
				return true; 
			}
		}
		return false; 
	}

	string moveBoard(string board) {
		int L = board.length(); 
		
		for (int i = 0; i < L - 1; i++) {
			if (board[i] == 'o' && board[i + 1] != 'o') {
				if (board[i + 2] == 'o' && board[i + 3] != 'o') {
					board[i + 3] = board[i]; 
					board[i] = '.'; 
				}
				board[i + 1] = board[i]; 
				board[i] = '.'; 
				return board; 
			}
		}

		for (int i = 0; i < L - 3; i++) {
			if (board[i] == 'o' && board[i + 1] == 'o' && 
				board[i + 2] == 'o' && board[i + 3] != 'o') {
				board[i + 3] = board[i]; 
				board[i] = '.'; 
				return board; 
			}
		}
		return board; 
	}
};
