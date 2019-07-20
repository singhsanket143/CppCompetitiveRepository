#include <iostream>
using namespace std;

int lps(string str) {
	int **dp = new int*[str.size()];
	for(int i=0;i<str.size();i++) {
		dp[i] = new int[str.size()]();
	}
	int n=str.size();
	// base case
	for(int i=0;i<n;i++) {
		dp[i][i] = 1;
	}

	for(int len=2;len<=n;len++) {
		for(int i=0;i<=n-len;i++) {
			int j=i+len-1;
			if(str[i]==str[j]) {
				dp[i][j] = 2+dp[i+1][j-1];
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}
	return dp[0][n-1];
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	cout<<lps(str);
	return 0;
}
