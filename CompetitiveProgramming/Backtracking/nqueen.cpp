#include <bits/stdc++.h>
using namespace std;

int board[11][11];

bool isSafe(int n, int row, int col) {
	// Same Column Check
	for(int i=row-1;i>=0;i--) {
		if(board[i][col] == 1) {
			return false;
		}
	}
	// Forward Diagnol Check
	for(int i=row-1, j=col+1; i>=0 and j<n; i--, j++) {
		if(board[i][j] == 1) {
			return false;
		}
	}
	// Backward Diagnol Check
	for(int i=row-1, j=col-1; i>=0 and j>=0; i--, j--) {
		if(board[i][j] == 1) {
			return false;
		}
	}
	return true;
}

void nqueenHelper(int n, int row) {
	if(row==n) {
		// Print the matrix
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout<<board[i][j]<<" ";
			}
		}
		cout<<endl;
	}

	for(int j=0;j<n;j++) {
		if(isSafe(n, row, j)) {
			board[row][j] = 1;
			nqueenHelper(n, row+1);
			board[row][j] = 0;
		}
	}
}

void placeQueen(int n) {
	memset(board, 0, 11*11*sizeof(int));
	nqueenHelper(n, 0);
}

int main(int argc, char const *argv[])
{
	placeQueen(4);
	return 0;
}
