#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *dp = new int[n+1]();
	for(int i=0;i<=6;i++) {
		dp[i] = i;
	}
	for(int i=7;i<=n;i++) {
		int result = INT_MIN;
		for(int j=i-3, x=2;j>=1;j--, x++) {
			result = max(result, dp[j]*(x));
		}
		dp[i] = result;
	}
	cout<<dp[n];
	return 0;
}
