#include <iostream>
using namespace std;
int dp[100] = {0};

int fpairDP(int n) {
	if(n==0) return 1;
	if(n==1) return 1;
	if(n==2) return 2;
	if(dp[n]!=0) {
		return dp[n];
	}
	// Assumption
	int r1 = fpairDP(n-1);
	int r2 = fpairDP(n-2);

	// Self work
	int result = r1+(n-1)*r2;
	dp[n] = result;
	return result;
}


int fpair(int n) {
	if(n==0) return 1;
	if(n==1) return 1;
	if(n==2) return 2;
	// Assumption
	int r1 = fpair(n-1);
	int r2 = fpair(n-2);

	// Self work
	return r1+(n-1)*r2;
}

int main(int argc, char const *argv[])
{
	cout<<fpair(4);
	return 0;
}
