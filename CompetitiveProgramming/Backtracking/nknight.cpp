#include <iostream>
using namespace std;

bool isValidPosition(int row, int col, int n) {
	return row>=0 and row<n and col>=0 and col<n;
}

bool isItSafe(bool **board, int n, int row, int col) {
	if(isValidPosition(row-2, col-1, n) and board[row-2][col-1]) {
		return false;
	}
	if(isValidPosition(row-2, col+1, n) and board[row-2][col+1]) {
		return false;
	}
	if(isValidPosition(row-1, col-2, n) and board[row-2][col-2]) {
		return false;
	}
	if(isValidPosition(row-1, col+2, n) and board[row-1][col+2]) {
		return false;
	}
	if(isValidPosition(row+1, col-2, n) and board[row+1][col-2]) {
		return false;
	}
	if(isValidPosition(row+1, col+2, n) and board[row+1][col+2]) {
		return false;
	}
	if(isValidPosition(row+2, col-1, n) and board[row+2][col-1]) {
		return false;
	}
	if(isValidPosition(row+2, col+1, n) and board[row+2][col+1]) {
		return false;
	}

	return true;
}

void printNknights(bool **board, int n, int placed, int sr, int sc, string osf) {
	if(placed == n) { // Base case
		cout<<osf<<endl;
		return;
	}

	for(int row=sr;row<n;row++) {
		for(int col = (row==sr)?sc:0; col<n;col++) {
			if(board[row][col] == false and isItSafe(board, n, row, col)) {
				board[row][col] = true;
				printNknights(board, n, placed+1, row, col+1, osf+"{"+to_string(row)+"-"+to_string(col)+"};");
				board[row][col] = false;
			}
		}
	}
}

int countNknights(bool **board, int n, int placed, int sr, int sc) {
	if(placed == n) { // Base case
		
		return 1;
	}
	int count = 0;
	for(int row=sr;row<n;row++) {
		for(int col = (row==sr)?sc:0; col<n;col++) {
			if(board[row][col] == false and isItSafe(board, n, row, col)) {
				board[row][col] = true;
				count+=countNknights(board, n, placed+1, row, col+1);
				board[row][col] = false;
			}
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	bool **board = new bool*[n];
	for(int i=0;i<n;i++) {
		board[i] = new bool[n];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			board[i][j] = false;
		}
	}
	printNknights(board, n, 0, 0, 0, "");
	cout<<countNknights(board, n, 0, 0, 0);
	return 0;
}
