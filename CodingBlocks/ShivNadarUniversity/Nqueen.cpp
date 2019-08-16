#include <iostream>
using namespace std;
bool visited[5][5];
int result = 0;

void display(int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(visited[i][j] == true) {
				cout<<"Q";
			} else {
				cout<<".";
			}
		}
		cout<<endl;
	}
}

bool isSafe(int row, int col, int n) {
	// upper area
	for(int i=row-1;i>=0;i--) {
		if(visited[i][col] == true) {
			return false;
		}
	}
	// left diagonal
	for(int i = row-1, j=col-1; i>=0 and j>=0; i--, j--) {
		if(visited[i][j] == true) {
			return false;
		}
	}
	// right diagonal
	for(int i = row-1, j=col+1; i>=0 and j<n; i--, j++) {
		if(visited[i][j] == true) {
			return false;
		}
	}

	// i am safe for this spot
	return true;
}

void nqueen(int curr_row, int n) {
	//base
	if(curr_row == n) {
		result++;
		display(n);
		cout<<endl<<endl;
		return;
	}
	for(int col = 0; col < n; col++) {
		if(isSafe(curr_row, col, n)) {
			visited[curr_row][col] = true;
			nqueen(curr_row+1, n);
			visited[curr_row][col] = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	nqueen(0, 5);
	cout<<result;
	return 0;
}
