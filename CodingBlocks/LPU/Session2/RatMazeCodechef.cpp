// cb.lk/lpu/rat
// 0 in visited array shows that the index has not been visited
#include <iostream>
using namespace std;

int result = 0;

bool isItSafe(int i, int j, int n) {
	return i>=0 and j>=0 and i<n and j<n;
}


void ratInMaze(int **maze, int **visited, int n, int i, int j) {
	if(maze[n-1][n-1] == 1) return;
	if(i == n-1 and j == n-1) {
		result++;
		return;
	}
	if(!isItSafe(i, j, n)) {
		return;
	}
	// Backtracking

	visited[i][j] = 1;
	// Work

	//UP
	if(isItSafe(i-1, j, n) and maze[i-1][j] == 0 and visited[i-1][j]==0){
		ratInMaze(maze, visited, n, i-1, j);
	}
	//RIGHT
	if(isItSafe(i, j+1, n) and maze[i][j+1] == 0 and visited[i][j+1]==0){
		ratInMaze(maze, visited, n, i, j+1);
	}
	//DOWN
	if(isItSafe(i+1, j, n) and maze[i+1][j] == 0 and visited[i+1][j]==0){
		ratInMaze(maze, visited, n, i+1, j);
	}
	//LEFT
	if(isItSafe(i, j-1, n) and maze[i][j-1] == 0 and visited[i][j-1]==0){
		ratInMaze(maze, visited, n, i, j-1);
	}
	// Now Bactrack
	visited[i][j] = 0;
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int **input = new int*[n];
	int **visited = new int*[n];
	for(int i=0;i<n;i++) {
		input[i] = new int[n];
		visited[i] = new int[n];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>input[i][j];
			visited[i][j] = 0;
		}
	}
	ratInMaze(input, visited, n, 0, 0);
	cout<<result<<endl;
	return 0;
}