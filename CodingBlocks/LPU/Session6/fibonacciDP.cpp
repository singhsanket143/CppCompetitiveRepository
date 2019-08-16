#include <iostream>
using namespace std;

int dp[100005] = {0};

int fibDP(int n) {
	if(n==0 or n==1) return n;
	if(dp[n] != 0) return dp[n];
	int cand1 = fibDP(n-1);
	int cand2 = fibDP(n-2);
	dp[n] = cand1+cand2;
	return cand1+cand2;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<fibDP(n);
	return 0;
}
