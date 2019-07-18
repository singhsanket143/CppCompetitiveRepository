#include <iostream>
using namespace std;

int fibDpBU(int n) {
	int *dp = new int[n+1]();
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<=n;i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	int result = dp[n];
	delete [] dp;
	return result;
}

int fibDpTD(int n, int *dp) {
	if(n==0 or n==1) return n;
	if(dp[n]!=0) {
		return dp[n];
	}

	int result = fibDpTD(n-1, dp) + fibDpTD(n-2, dp);
	dp[n] = result;
	return result;
}

int fib(int n) {
	if(n==0 or n==1) return n;
	return fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *dp = new int[n+1]();
	cout<<fibDpTD(n, dp)<<endl;
	cout<<fibDpBU(n)<<endl;
	cout<<fib(n);
	return 0;
}
