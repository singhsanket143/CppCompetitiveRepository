#include <iostream>
#include "cstring"
using namespace std;

int dp[1005][1005];

int minDeletions(string str) {
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<str.size();i++) {
		dp[i][i] = 1;
	}
	for(int l=2;l<=str.size();l++) {
		
		for(int i = 0; i < str.size(); i++) {
			int j = i + l -1;
			if(str[i] == str[j]) {
				dp[i][j] = dp[i+1][j-1] + 2 - (i==j);
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}
	return str.size() - dp[0][str.size()-1];
}

int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	while(t--) {
		string str;
	cin>>str;
	cout<<minDeletions(str)<<endl;
	}
	
	return 0;
}
