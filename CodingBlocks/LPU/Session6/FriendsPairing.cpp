#include <iostream>
using namespace std;

int dp[100005] = {0};

int friendsDP(int n) {
	// Base case
	if(n==0 or n==1) return 1;
	if(n==2) return 2;
	if(dp[n]!=0) return dp[n];
	int result = friendsDP(n-1) + ((n-1)*friendsDP(n-2));
	dp[n] = result;
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<friendsDP(n);
	return 0;
}
