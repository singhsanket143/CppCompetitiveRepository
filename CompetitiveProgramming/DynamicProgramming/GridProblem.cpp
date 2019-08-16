#include <iostream>
using namespace std;

int gridCost(int arr[][100], int row, int col) {
	int dp[100][100];
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = arr[0][0];
	for(int i=1;i<row;i++) {
		dp[i][0] = dp[i-1][0] + arr[i][0];
	}
	for(int i=1;i<col;i++) {
		dp[0][i] = dp[0][i-1] + arr[0][i];
	}
	for(int i=1;i<row;i++) {
		for(int j=1;j<col;j++) {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
		}
	}
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[row-1][col-1];
}

int main(int argc, char const *argv[])
{
	int grid[100][100] = {
		{1, 2, 3},
		{4, 8, 2},
		{1, 5, 3}
	};
	cout<<gridCost(grid, 3, 3);
	return 0;
}
