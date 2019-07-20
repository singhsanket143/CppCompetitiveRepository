#include <iostream>
using namespace std;

int secondMin(int *arr, int k, int firstMinIdx) {
	int idx = -1;
	int result = INT_MAX;
	for(int i=0;i<k;i++) {
		if(arr[i]<result and i!=firstMinIdx) {
			result = arr[i];
			idx = i;
		}
	}
	return idx;
}

int firstMin(int *arr, int k) {
	int result = INT_MAX;
	int idx = -1;
	for(int i=0;i<k;i++) {
		if(arr[i]<result) {
			result = arr[i];
			idx = i;
		}
	}
	return idx;
}

int paintHouse(int **arr, int n, int k) {
	int **dp = new int*[n];
	for(int i=0;i<n;i++) {
		dp[i] = new int[k]();
	}
	for(int i=0;i<k;i++) {
		dp[0][i] = arr[0][i];
	}

	for(int i=1;i<n;i++) {
		int firstMinIdx = firstMin(dp[i-1], k);
		int secondMinIdx = secondMin(dp[i-1], k, firstMinIdx);
		for(int j=0;j<k;j++) {
			if(dp[i-1][j] == dp[i-1][firstMinIdx]) {
				dp[i][j] = arr[i][j] + dp[i-1][secondMinIdx];
			} else {
				dp[i][j] = arr[i][j] + dp[i-1][firstMinIdx];
			}
		}
	}
	int retval = INT_MAX;
	for(int i=0;i<k;i++) {
		retval = min(retval, dp[n-1][i]);
	}
	return retval;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
