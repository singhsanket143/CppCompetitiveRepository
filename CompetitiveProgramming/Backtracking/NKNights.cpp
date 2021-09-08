#include <iostream>
using namespace std;

bool isValidPosition(int row, int col, int N) {
	return row >= 0 && row < N && col >= 0 && col < N;
}

bool isItSafe(bool **board, int n, int row, int col) {
		if (isValidPosition(row - 2, col - 1, n) && board[row - 2][col - 1]) {
			return false;
		} else if (isValidPosition(row - 2, col + 1, n) && board[row - 2][col + 1]) {
			return false;
		} else if (isValidPosition(row - 1, col - 2, n) && board[row - 1][col - 2]) {
			return false;
		} else if (isValidPosition(row - 1, col + 2, n) && board[row - 1][col + 2]) {
			return false;
		} 

		return true;
}
int ways = 0;
void printNKnights(bool **board,int n, int placed, int sr, int sc, string osf) {
		if (placed == n) {
			cout<< osf << endl;;
			ways++;
			return;
		}

		for (int row = sr; row < n; row++) {
			for (int col = (row == sr? sc: 0) ; col < n; col++) {
				if (board[row][col] == false && isItSafe(board, n, row, col)) {
					board[row][col] = true;
					printNKnights(board, n, placed + 1, row, col + 1, osf + "{" + to_string(row) + "-" + to_string(col) + "}; ");
					board[row][col] = false;
				}
			}
		}
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	bool **board = new bool*[n];
	for(int i=0;i<n;i++) {
		board[i] = new bool[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			board[i][j] = false;
		}
	}
	printNKnights(board, n, 0, 0, 0, "");
	std::cout<<ways<<"\n";
	return 0;
}
