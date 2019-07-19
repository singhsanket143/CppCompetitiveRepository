#include <iostream>
using namespace std;

int maxValue(int n) {
	if(n<=6) return n;
	int *dp = new int[n+1];
	for(int i=0;i<=6;i++) {
		dp[i] = i;
	}
	for(int i=7;i<=n;i++) {
		int result = INT_MIN;
		for(int j=i-3, a = 2; j>=1 and a<=(i/2)+1;a++, j--) {
			result = max(result, dp[j]*a);
		}
		dp[i] = result;
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	return 0;
}
