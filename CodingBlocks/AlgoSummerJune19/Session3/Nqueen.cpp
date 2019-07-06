#include <iostream>
using namespace std;
int result = 0;

void print(bool **visited, int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(visited[i][j] == false) {
				cout<<".";
			} else {
				cout<<"Q";
			}
		}
		cout<<"\n";
	}
}

bool safe(bool **visited, int row, int col, int n) {
	// for column
	for(int i=row-1;i>=0;i--) {
		if(visited[i][col] == true) {
			return false;
		}
	}

	// Piche wala diagonal
	for(int i=row-1, j=col-1;i>=0 and j>=0; i--, j--) {
		if(visited[i][j] == true) {
			return false;
		}
	}
	// Aage wala diagonal
	for(int i=row-1, j=col+1;i>=0 and j<n;i--, j++) {
		if(visited[i][j] == true) {
			return false;
		}
	}
	return true;
}

void Nqueen(int n, bool **visited, int row) {
	if(row == n) {
		result++;
		print(visited, n);
		cout<<"*************************\n";
		return;
	}
	for(int i=0;i<n;i++) {
		if(safe(visited, row, i, n)) {
			visited[row][i] = true;
			Nqueen(n, visited, row+1);
			visited[row][i] = false;
		}
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	bool **visited = new bool*[n];
	for(int i=0;i<n;i++) {
		visited[i] = new bool[n]();
	}
	Nqueen(n, visited, 0);
	cout<<result;
	return 0;
}
