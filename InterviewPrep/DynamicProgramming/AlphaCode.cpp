#include <iostream>
using namespace std;

int alphaCodeTD(int *input, int n, int *dp) {
	if(n==1 or n==0) return 1;
	if(dp[n]!=0) return dp[n];

	int result = 0;
	result += alphaCodeTD(input, n-1, dp);
	if(input[n-2]*10+input[n-1]<=26) {
		result += alphaCodeTD(input, n-2, dp);
	}
	dp[n] = result;
	return result;
}

int alphaCodeBU(int *input, int n) {
	int *dp = new int[n+1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++) {
		dp[i] = dp[i-1];
		if(input[i-2]*10+input[i-1]<=26) {
			dp[i] += dp[i-2];
		}
	}
	int ans = dp[n];
	delete [] dp;
	return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while(n!=0) {
        string str = to_string(n);
	    int *input = new int[str.size()];
	    for(int i=0;i<str.size();i++) {
	    	input[i] = str[i]-'0';
	    }
        cout<<alphaCodeBU(input, str.size());
        delete [] input;
        cin>>n;
    }
	
	return 0;
}
