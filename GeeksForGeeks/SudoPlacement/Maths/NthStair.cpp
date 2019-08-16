#include <iostream>
using namespace std;
int dp[100005];
int stairs(int n) {
	if(n==1 or n==2) {
		return 1;
	}

	if(dp[n]!=0) return dp[n];

	int result = stairs(n-1)+stairs(n-2);
	return dp[n]=result;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		dp={0};
		int n;
		cin>>n;
	}
	return 0;
}
