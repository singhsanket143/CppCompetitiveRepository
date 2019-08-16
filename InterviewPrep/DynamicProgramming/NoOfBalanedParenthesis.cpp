#include <iostream>
using namespace std;

int balancedParenthesis(int n, int *dp) {
	if(n==0) return 1;
	if(n==1) return 1;
	int result = 0;
	if(dp[n]!=0) return dp[n];
	for(int i=1;i<=n;i++) {
		result += balancedParenthesis(i-1, dp)*balancedParenthesis(n-i, dp);
	}
	dp[n] = result;
	return result;	
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *dp = new int[n+1]();
	cout<<balancedParenthesis(n, dp);
	return 0;
}
