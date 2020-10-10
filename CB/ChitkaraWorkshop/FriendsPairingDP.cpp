#include <iostream>
using namespace std;
int fpDPBU(int n) {
	int dp[100] = {0};
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2;i<=n;i++) {
		dp[i] = dp[i-1]+ dp[i-2]*(i-1);
	}
	return dp[n];
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
