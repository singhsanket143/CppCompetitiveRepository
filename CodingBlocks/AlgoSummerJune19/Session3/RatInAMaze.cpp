#include <iostream>
using namespace std;

int result = 0;

bool isItSafe(int i, int j, int n) {
	return i>=0 and j>=0 and i<n and j<n;
}

void ratInMaze(int **maze, bool **visited, int i, int j, int n) {
	// Base case
	if(maze[i][j] == 1) {
		return;
	}
	if(i==n-1 and j==n-1) {
		result++;
		return;
	}

	visited[i][j] = true;
	// work
	if(isItSafe(i-1, j, n) and maze[i-1][j]==0 and visited[i-1][j]==false) {
		ratInMaze(maze, visited, i-1, j, n);
	}
	if(isItSafe(i, j-1, n) and maze[i][j-1]==0 and visited[i][j-1]==false) {
		ratInMaze(maze, visited, i, j-1, n);
	}
	if(isItSafe(i, j+1, n) and maze[i][j+1]==0 and visited[i][j+1]==false) {
		ratInMaze(maze, visited, i, j+1, n);
	}
	if(isItSafe(i+1, j, n) and maze[i+1][j]==0 and visited[i+1][j]==false) {
		ratInMaze(maze, visited, i+1, j, n);
	}
	visited[i][j] = false;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int **arr = new int*[n];
	for(int i=0;i<n;i++) {
		arr[i] = new int[n];
	}
	bool **visited = new bool*[n];
	for(int i=0;i<n;i++) {
		visited[i] = new bool[n]();
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>arr[i][j];
		}
	}
	if(arr[n-1][n-1]==1) {
		cout<<0;
	} else {
		ratInMaze(arr, visited, 0, 0, n);
		cout<<result;
	}
	return 0;
}
