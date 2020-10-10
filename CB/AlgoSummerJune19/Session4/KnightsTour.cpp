#include <iostream>
using namespace std;

void display(int **grid,int m ,int n) {
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isItSafe(int m, int n, int **grid, int i, int j) {
	return i>=0 and j>=0 and i<m and j<n and grid[i][j] == -1;
}

void Nknights(int **grid, int csf, int cr, int cc, int m, int n) {

	if(csf == m*n-1) {
		grid[cr][cc] = csf;
		display(grid, m, n);
		cout<<endl;
		grid[cr][cc] = -1;
		return; 
	}

	if(isItSafe(m, n, grid, cr+1, cc+2)) {
		grid[cr][cc] = csf;
		Nknights(grid, csf+1, cr+1, cc+2, m, n);
		grid[cr][cc] = -1;
	}
	if(isItSafe(m, n, grid, cr+2, cc+1)) {
		grid[cr][cc] = csf;
		Nknights(grid, csf+1, cr+2, cc+1, m, n);
		grid[cr][cc] = -1;
	}
	if(isItSafe(m, n, grid, cr+1, cc-2)) {
		grid[cr][cc] = csf;
		Nknights(grid, csf+1, cr+1, cc-2, m, n);
		grid[cr][cc] = -1;
	}
	if(isItSafe(m, n, grid, cr+2, cc-1)) {
		grid[cr][cc] = csf;
		Nknights(grid, csf+1, cr+2, cc-1, m, n);
		grid[cr][cc] = -1;
	}

	if(isItSafe(m, n, grid, cr-1, cc+2)) {
		grid[cr][cc] = csf;
		Nknights(grid, csf+1, cr-1, cc+2, m, n);
		grid[cr][cc] = -1;
	}
	if(isItSafe(m, n, grid, cr-2, cc+1)) {
		grid[cr][cc] = csf;
		Nknights(grid, csf+1, cr-2, cc+1, m, n);
		grid[cr][cc] = -1;
	}
	if(isItSafe(m, n, grid, cr-1, cc-2)) {
		grid[cr][cc] = csf;
		Nknights(grid, csf+1, cr-1, cc-2, m, n);
		grid[cr][cc] = -1;
	}
	if(isItSafe(m, n, grid, cr-2, cc-1)) {
		grid[cr][cc] = csf;
		Nknights(grid, csf+1, cr-2, cc-1, m, n);
		grid[cr][cc] = -1;
	}


}


int main(int argc, char const *argv[])
{
	int m, n;
	cin>>m>>n;
	int **grid = new int*[m];
	for(int i=0;i<m;i++) {
		grid[i] = new int[n];
	}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			grid[i][j] = -1;
		}
	}
	Nknights(grid, 0 , 0, 0, m, n);
	return 0;
}
