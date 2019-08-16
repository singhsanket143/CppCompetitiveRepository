#include <iostream>
using namespace std;

void display(int **grid, int m, int n) {
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) {
			cout<<grid[i][j]<<"\t";
		}
		cout<<endl;
	}
}

bool isItSafe(int **grid, int x, int y, int m , int n) {
	return x>=0 and y>=0 and x<m and y<n and grid[x][y]==-1;
}

void knightsTour(int **grid, int x, int y, int m, int n, int csf) {
	// base case
	if(csf == m*n-1) {
		grid[x][y] = csf;
		display(grid, m, n);
		cout<<"\n\n";
		grid[x][y] = -1;
		return;
	}

	if(isItSafe(grid, x+1, y+2, m, n)) {
		// Work
		grid[x][y] = csf;
		knightsTour(grid, x+1, y+2, m, n, csf+1) ;
		grid[x][y]=-1;
		
	}

	if(isItSafe(grid, x-1, y+2, m, n)) {
		// Work
		grid[x][y] = csf;
		knightsTour(grid, x-1, y+2, m, n, csf+1);
		
			grid[x][y]=-1;
		
	}

	if(isItSafe(grid, x+2, y-1, m, n)) {
		// Work
		grid[x][y] = csf;
		knightsTour(grid, x+2, y-1, m, n, csf+1);
		
			grid[x][y]=-1;
		
	}

	if(isItSafe(grid, x+2, y+1, m, n)) {
		// Work
		grid[x][y] = csf;
		knightsTour(grid, x+2, y+1, m, n, csf+1);
		
			grid[x][y]=-1;
		
	}

	if(isItSafe(grid, x+1, y-2, m, n)) {
		// Work
		grid[x][y] = csf;
		knightsTour(grid, x+1, y-2, m, n, csf+1);
		
			grid[x][y]=-1;
		
	}

	if(isItSafe(grid, x-1, y-2, m, n)) {
		// Work
		grid[x][y] = csf;
		knightsTour(grid, x-1, y-2, m, n, csf+1);
		
			grid[x][y]=-1;
		
	}

	if(isItSafe(grid, x-2, y-1, m, n)) {
		// Work
		grid[x][y] = csf;
		knightsTour(grid, x-2, y-1, m, n, csf+1);
		 
			grid[x][y]=-1;
		
	}

	if(isItSafe(grid, x-2, y+1, m, n)) {
		// Work
		grid[x][y] = csf;
		knightsTour(grid, x-2, y+1, m, n, csf+1);
		grid[x][y]=-1;
		
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int m, n;
	cin>>m>>n;
	int **arr = new int*[m];
	for(int i=0;i<m;i++) {
		arr[i] = new int[n];
	}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			arr[i][j]=-1;
		}
	}
	knightsTour(arr, 2, 2, m ,n, 0);
		
	
	return 0;
}