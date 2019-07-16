#include <iostream>
using namespace std;
bool visited[7][7];
int result = 0;
bool input[7][7];
bool isSafe(int i, int j, int n) {
	return i>=0 and j>=0 and i<n and j<n and input[i][j]==0 and visited[i][j]==false;
}

void ratInMaze(int x, int y, int n) {
	if(x==n-1 and y==n-1) {
		result++;
		return;
	}
	visited[x][y] = true;
	if(isSafe(x-1, y, n)) {
		ratInMaze(x-1, y, n);
	}
	if(isSafe(x, y-1, n)) {
		ratInMaze(x, y-1, n);
	}
	if(isSafe(x+1, y, n)) {
		ratInMaze(x+1, y, n);
	}
	if(isSafe(x, y+1, n)) {
		ratInMaze(x, y+1, n);
	}
	visited[x][y] = false;
	return;
}



int main(int argc, char const *argv[])
{
	for(int i=0;i<7;i++) {
		for(int j=0;j<7;j++) {
			visited[i][j] = false;
		}
	}
	for(int i=0;i<7;i++) {
		for(int j=0;j<7;j++) {
			cin>>input[i][j];
		}
	}
	ratInMaze(0, 0, 7);
	cout<<result<<endl;
	return 0;
}
