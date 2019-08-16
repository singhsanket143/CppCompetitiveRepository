#include <iostream>
using namespace std;
int result = 0;
bool isItSafe(bool **grid, int row, int col, int n) {
	// Column check
	for(int i = row-1; i >= 0; i--) {
		if(grid[i][col]==true) {
			return false; // Not safe
		}
	}
	// piche wala diagnol
	for(int i=row-1, j=col-1;i>=0 and j>=0; i--, j--) {
		if(grid[i][j]==true) {
			return false;
		}
	}

	// Aage wala diagnol
	for(int i=row-1, j=col+1; i>=0 and j<n;i--, j++) {
		if(grid[i][j]==true) {
			return false;
		}
 	}

 	return true; // Safe
}

void display(bool **grid, int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(grid[i][j]==false) {
				cout<<".";
			} else {
				cout<<"Q";
			}
		}
		cout<<endl;
	}
}

void countNQueen(bool **grid, int curr_row, int n) {
	if(curr_row == n) {
		// Result Extaction
		result++;
		display(grid, n);
		cout<<"\n";
		return;
	}

	for(int col=0;col<n;col++) {
		if(isItSafe(grid, curr_row, col, n) == true) {
			grid[curr_row][col] = true;
			countNQueen(grid, curr_row+1, n);
			grid[curr_row][col]=false;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	bool **grid = new bool*[n];
	for(int i=0;i<n;i++) {
		grid[i] = new bool[n];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			grid[i][j] = false;
		}
	}
	countNQueen(grid, 0, n);
	cout<<endl;
	cout<<result<<endl;
	return 0;
}
