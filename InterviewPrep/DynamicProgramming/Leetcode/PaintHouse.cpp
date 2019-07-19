#include <iostream>
#include <vector>
using namespace std;

int secondMin(int **arr, int n, int k, int row, int firstMinIdx) {
	int result = INT_MAX;
	int idx = 0;
	for(int i=0;i<k;i++) {
		if(arr[row][i]<result and i!=firstMinIdx) {
			result = arr[row][i];
			idx = i;
		}
	}
	return idx;
}

int firstMin(int **arr, int n, int k, int row) {
	int result = arr[row][0];
	int idx = 0;
	for(int i=0;i<k;i++) {
		if(arr[row][i]<result) {
			result = arr[row][i];
			idx = i;
		}
	}
	return idx;
}

int minCost(vector<vector<int> > &costs, int k) {
	int n = costs.size();
	if(n==0) return 0;
	int **dp = new int*[n];
	for(int i=0;i<n;i++) {
		dp[i] = new int[k]();
	}
	for(int j=0;j<k;j++) {
		dp[0][j] = costs[0][j];
	}
	for(int i=1;i<n;i++) {
	    for(int j=0;j<k;j++) {
	        dp[i][j] = INT_MAX;
	    }
	}
	for(int i=1;i<n;i++) {
		int firstMinIdx = firstMin(dp, n, k, i-1);
		int secondMinIdx = secondMin(dp, n, k, i-1, firstMinIdx);
		cout<<firstMinIdx<<", "<<secondMinIdx<<endl;
		
		for(int j=0;j<k;j++) {
			if(j==firstMinIdx) {
				dp[i][j] = min(dp[i][j], dp[i-1][secondMinIdx]+costs[i][j]);
			} else {
				dp[i][j] = min(dp[i][j], dp[i-1][firstMinIdx]+costs[i][j]);
			}
		}
	}
	for(int i=0;i<n;i++) {
	    for(int j=0;j<k;j++) {
	        cout<<dp[i][j]<<" ";
	    }
	    cout<<endl;
	}
	int result = INT_MAX;
	for(int j=0;j<k;j++) {
		if(result > dp[n-1][j]) {
			result = dp[n-1][j];
		}
	}
	return result;
}
int minCostII(vector<vector<int>> &costs) {
        // write your code here
        if(costs.size() == 0) return 0;
        return minCost(costs, costs[0].size());
}

int main(int argc, char const *argv[])
{
	return 0;
}
