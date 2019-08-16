#include <iostream>
using namespace std;

void mazeHelp(int maze[][20], int** solution,int n, int x, int y) {
	if(x==n-1 and y==n-1) {
		solution[x][y] = 1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout<<solution[i][j]<<" ";
			}
			cout<<endl;
		}
		solution[x][y] =0;
		return;
	}
	if(x<0 or y<0 or x>=n or y>=n or maze[x][y]==0 or solution[x][y]==1) {
		return;
	}
	solution[x][y] = 1;
	mazeHelp(maze, solution, n, x-1, y);
	mazeHelp(maze, solution, n, x+1, y);
	mazeHelp(maze, solution, n, x, y-1);
	mazeHelp(maze, solution, n, x, y+1);
	solution[x][y] = 0;

}

void ratInAMaze(int n, int maze[][20]) {
	int** solution = new int*[n];
	for(int i=0;i<n;i++) {
		solution[i] = new int[n];
	}
	mazeHelp(maze, solution, n, 0, 0);
}

int main(int argc, char const *argv[])
{
	return 0;
}