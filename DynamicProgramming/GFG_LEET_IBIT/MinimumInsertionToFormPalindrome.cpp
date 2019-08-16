#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1005][10005];

int minInsertionsBUDP(string str) {
	memset(dp, 0, sizeof(dp));
	int n = str.size();
	for(int gap=1;gap<n;gap++) {
		int l = 0;
		for(int h=gap;h<n;h++) {
			if(str[l] == str[h]) {
				dp[l][h] = dp[l+1][h-1];
			} else {
				dp[l][h] = min(dp[l+1][h], dp[l][h-1]) + 1;
			}
			l++;
		}

	}
	return dp[0][str.size()-1];
}

int minInsertionsLCS(string str) {
	string rev = str;
	reverse(rev.begin(), rev.end());
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<=str.size();i++) {
		for(int j=1;j<=rev.size();j++) {
			if(str[i-1] == rev[j-1]) {
				dp[i][j] = 1+dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	int retval = dp[str.size()][rev.size()];
	return str.size() - retval;
}

int minInsertions(string str, int l, int h) {
	if(l > h) return INT_MAX;
	if(l == h) return 0;
	if(l == h-1) return (str[l] == str[h])?0:1;
	return (str[l] == str[h])?minInsertions(str, l+1, h-1):min(minInsertions(str, l+1, h), minInsertions(str, l, h-1))+1; 
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	string str;
	cin>>str;
	cout<<minInsertionsBUDP(str)<<endl;
	// cout<<minInsertionsLCS(str)<<endl;
	// cout<<minInsertions(str, 0, str.size() - 1);
	return 0;
}
