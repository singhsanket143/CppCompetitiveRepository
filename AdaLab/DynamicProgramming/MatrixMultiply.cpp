#include <iostream>
using namespace std;

int matrixMultiply(int arr[], int **dp, int i, int j, int n) {
	if(i == j) {
		return 0;
	}
	if(dp[i][j] != 0) {
		return dp[i][j];
	}
	int minCost = INT_MAX;
	for(int k=i;k<j;k++) {
		int possibleAns = matrixMultiply(arr, dp, i, k, n) + matrixMultiply(arr, dp, k+1, j, n) + arr[i-1]*arr[k]*arr[j];
		minCost = min(minCost, possibleAns);
	}
	return minCost;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
