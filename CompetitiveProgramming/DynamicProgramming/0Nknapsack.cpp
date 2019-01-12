#include <iostream>
using namespace std;

int unboundedKnapsack(int *vals, int *wts, int W, int n) {
	int dp[W+1];
	memset(dp, 0, sizeof dp); 
	for(int i=0;i<=W;i++) {
		for(int j=0;j<n;j++) {
			if(wts[j]<=i)
				dp[i] = max(dp[i], dp[i-wts[j]]+vals[j]);
		}
	}
	
	return dp[W];
}

int main(int argc, char const *argv[])
{
	
	int W = 11; 
    int val[] = {4, 3, 5, 6, 1}; 
    int wt[] = {3, 2, 4, 5, 1}; 
    int n = sizeof(val)/sizeof(val[0]); 
  
    cout << unboundedKnapsack(val, wt, W, n); 
	return 0;
}
