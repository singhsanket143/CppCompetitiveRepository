#include <iostream>
using namespace std;

int dp[100] = {0};

int fibDPBU(int n) {
	int dp[100] = {0};
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2;i<=n;i++) {
		dp[i] = dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int fibDPTD(int n) {
	if(n==0 or n==1)return n;
	if(dp[n]!=0) {
		return dp[n];
	}
	int result = fibDPTD(n-1)+fibDPTD(n-2);
	dp[n] = result;
	return result;
}

int fib(int n) {
	if(n==0 or n==1)return n;

	return fib(n-1)+fib(n-2);
}

int main(int argc, char const *argv[])
{
	cout<<fibDPTD(50)<<endl;
	cout<<fibDPBU(50)<<endl;
	cout<<fib(50)<<endl;
	return 0;
}
