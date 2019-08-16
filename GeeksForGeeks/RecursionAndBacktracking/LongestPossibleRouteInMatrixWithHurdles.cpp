#include <iostream>
using namespace std;
class Pair {
public:
	bool found;
	int value;
};
Pair longestPathHelper(int **matrix, int i, int j, int x, int y, bool **visited, int m, int n) {
	if(i==x and j==y) {
		return {true, 0};
	}
	if(i<0 or j<0 or i>=m or j>=n or visited[i][j] or matrix[i][j]==0) {
		return {false, INT_MAX};
	}
	visited[i][j] = true;
	Pair sol; int result = INT_MIN;
	
	sol = longestPathHelper(matrix, i, j-1, x, y, visited, m, n);
	if(sol.found) {
		result = max(result, sol.value);
	}
	sol = longestPathHelper(matrix, i, j+1, x, y, visited, m, n);
	if(sol.found) {
		result = max(result, sol.value);
	}
	sol = longestPathHelper(matrix, i-1, j, x, y, visited, m, n);
	if(sol.found) {
		result = max(result, sol.value);
	}
	sol = longestPathHelper(matrix, i+1, j, x, y, visited, m, n);
	if(sol.found) {
		result = max(result, sol.value);
	}
	// Backtrack step
	visited[i][j] = false;
	if(result != INT_MIN) {
		return {true, 1+result};
	} else {
		return {false, INT_MAX};
	}
}

void longestPath(int **matrix, int x, int y, int m, int n) {
	bool **visited = new bool*[m];
	for(int i=0;i<m;i++) {
		visited[i] = new bool[n];
	}
	Pair p = longestPathHelper(matrix, 0, 0, x, y, visited, m, n);
	if (p.found) 
        cout << p.value; 
    else
        cout << -1;
}

int main(int argc, char const *argv[])
{
	int m, n, x, y;
	cin>>m>>n;
	int **matrix = new int*[m];
	for(int i=0;i<m;i++) {
		matrix[i] = new int[n];
	}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cin>>matrix[i][j];
		}
	}
	cin>>x>>y;
	longestPath(matrix, x, y, m, n);
	return 0;
}
