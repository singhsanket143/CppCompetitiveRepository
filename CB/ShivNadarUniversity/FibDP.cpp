#include <iostream>
using namespace std;
int dp[100] = {0};

int fibBUDP(int n) {
	int dparr[100] = {0};
	dparr[0] = 0;
	dparr[1] = 1;
	for(int i=2;i<=n;i++) {
		dparr[i] = dparr[i-1] + dparr[i-2];
	}
	return dparr[n];
}

int fibDP(int n) {
	if(n==0 or n==1) return n;
	if(dp[n]!=0) {
		return dp[n];
	}
	int result = fibDP(n-1) + fibDP(n-2);
	dp[n] = result;
 	return result;
}

int fib(int n) {
	if(n==0 or n==1) return n;
	return fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[])
{
	cout<<fibDP(60)<<endl;
	cout<<fibBUDP(60)<<endl;
	cout<<fib(60)<<endl;
	return 0;
}
