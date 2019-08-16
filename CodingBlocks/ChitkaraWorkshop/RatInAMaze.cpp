#include <iostream>
using namespace std;
bool visited[7][7];
int result = 0;

bool isSafe(int x, int y, int n) {
	return x>=0 and y>=0 and x<n and y<n;
}

void ratInMaze(int x, int y, int input[][7]) {
	if(x == 6 and y == 6) {
		result++;
		return;
	}
	visited[x][y] = true;
	if(isSafe(x-1, y, 7) and input[x-1][y]==0 and visited[x-1][y] == false) {
		ratInMaze(x-1, y, input);
	}
	if(isSafe(x, y-1, 7) and input[x][y-1]==0 and visited[x][y-1] == false) {
		ratInMaze(x, y-1, input);
	}
	if(isSafe(x+1, y, 7) and input[x+1][y]==0 and visited[x+1][y] == false) {
		ratInMaze(x+1, y, input);
	}
	if(isSafe(x, y+1, 7) and input[x][y+1]==0 and visited[x][y+1] == false) {
		ratInMaze(x, y+1, input);
	}
	visited[x][y] = false;
	return;
}

int main(int argc, char const *argv[])
{
	
	int input[7][7];
	for(int i=0;i<7;i++) {
		for(int j=0;j<7;j++) {
			cin>>input[i][j];
		}
	}
	for(int i=0;i<7;i++) {
		for(int j=0;j<7;j++) {
			visited[i][j] = false;
		}
	}
	ratInMaze(0, 0, input);
	cout<<result;
	return 0;
}
