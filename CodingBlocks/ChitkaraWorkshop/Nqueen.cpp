#include <iostream>
using namespace std;
int result = 0;
bool visited[10][10];

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

bool isItSafe(int row, int col, int n) {
	// Upper area
	for(int i=row-1;i>=0;i--) {
		if(visited[i][col] == true) {
			return false;
		}
	}

	// left diagnol
	for(int i=row-1, j=col-1;i>=0 and j>=0; i--, j--) {
		if(visited[i][j] == true) {
			return false;
		}
	}
	// Right diagnoal
	for(int i=row-1, j=col+1;i>=0 and j<n;i--, j++) {
		if(visited[i][j] == true) {
			return false;
		}
	}

	// You are safe
	return true;
}
 
void Nqueen(int row, int n) {
	if(row == n) {
		result++;
		display(n);
		cout<<"*********************\n";
		return;
	}

	for(int col = 0; col < n; col++) {
		if(isItSafe(row,col, n)) {
			visited[row][col] = true;
			Nqueen(row+1, n);
			visited[row][col] = false;
		}
	}
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			visited[i][j] = false;
		}
	}
	Nqueen(0, n);
	cout<<result;
	return 0;
}
