#include <iostream>
#include <algorithm>
using namespace std;
const int inf = (int)1e9;
int memo[10000];
 
int* reduceNo_bottomup(int n) {
	int *dp = new int[20000001];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	// if(n==0 or n==1 or n==2 or n==3) {
	// 	return dp[n];
	// }
	for(int i=4;i<=n;i++) {
		int factor_of_3 = inf;
		int factor_of_2 = inf;
		int diff_of_1 = inf;
		if(i%3 == 0) factor_of_3 = 1 + dp[i/3];
		if(i%2 == 0) factor_of_2 = 1 + dp[i/2];
		diff_of_1 = 1 + dp[i-1];
		dp[i] = min(factor_of_3, min(factor_of_2, diff_of_1));
	}
	//int result = dp[n];
	//delete [] dp;
	return dp;
}
 
int reduceNo_topdown(int n) {
	if(n == 1 or n == 0) {
		return 0;
	}
	if(memo[n] != -1) {
		return memo[n];
	}
	int factor_of_3 = inf;
	int factor_of_2 = inf;
	int diff_of_1 = inf;
	if(n%3 == 0) factor_of_3 = 1 + reduceNo_topdown(n/3);
	if(n%2 == 0) factor_of_2 = 1 + reduceNo_topdown(n/2);
	diff_of_1 = 1 + reduceNo_topdown(n-1);
	memo[n] = min(factor_of_3, min(factor_of_2, diff_of_1));
	return memo[n];
}
 
int reduceNo(int n) {
	if(n == 1 or n == 0) {
		return 0;
	}
	int factor_of_3 = inf;
	int factor_of_2 = inf;
	int diff_of_1 = inf;
	if(n%3 == 0) factor_of_3 = 1 + reduceNo(n/3);
	if(n%2 == 0) factor_of_2 = 1 + reduceNo(n/2);
	diff_of_1 = 1 + reduceNo(n-1);
 
	return min(factor_of_3, min(factor_of_2, diff_of_1));
}
 
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int *dp = reduceNo_bottomup(20000000);
	int c=1;
	while(t--) {
		int n;
		cin>>n;
		// cout<<reduceNo(n);
		//fill(memo, memo+n+1, -1);
		cout<<"Case "<<c++<<": "<<dp[n]<<endl;
	}
	
	return 0;
}