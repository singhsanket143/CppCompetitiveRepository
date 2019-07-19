#include <iostream>
using namespace std;

int knapsackBU(int *wts, int *cost, int n, int tw) {
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = new int[tw+1];
	}
	for(int i=0;i<=n;i++) {
		dp[i][0] = 0;
	}
	for(int i=0;i<=tw;i++) {
		dp[0][i] = 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=tw;j++) {
			if(wts[i-1] <= j) {
				// take
				dp[i][j] = max(dp[i-1][j], cost[i-1] + dp[i-1][j-wts[i-1]]);
			} else {
				// leave
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][tw];
}

int knapsackTD(int *wts, int *cost, int n, int tw, int ci, int **dp) {
	if(ci == n) {
		return 0;
	}
	if(tw <= 0) {
		return 0;
	}
	if(dp[ci][tw]!=0) {
		return dp[ci][tw];
	}
	int leave = INT_MIN;
	int take = INT_MIN;
	if(wts[ci] <= tw) {
		take = cost[ci] + knapsackTD(wts, cost, n, tw-wts[ci], ci+1, dp);
	}
	leave = knapsackTD(wts, cost, n, tw, ci+1, dp);
	return dp[ci][tw] = max(leave, take);
}

int knapsack(int *wts, int *cost, int n, int tw, int ci) {
	if(ci == n) {
		return 0;
	}
	if(tw <= 0) {
		return 0;
	}
	int leave = INT_MIN;
	int take = INT_MIN;
	if(wts[ci] <= tw) {
		take = cost[ci] + knapsack(wts, cost, n, tw-wts[ci], ci+1);
	}
	leave = knapsack(wts, cost, n, tw, ci+1);

	return max(leave, take);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int tw;
	cin>>tw;
	int *wts= new int[n];
	int *cost = new int[n];
	for(int i=0;i<n;i++) {
		cin>>wts[i];
	}
	for(int i=0;i<n;i++) {
		cin>>cost[i];
	}
	cout<<knapsackBU(wts, cost, n, tw)<<endl;
	cout<<knapsack(wts, cost, n, tw, 0)<<endl;
	return 0;
}
