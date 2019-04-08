#include <iostream>
#include <cstring>
using namespace std;

int dp[1005][1005];

int longestPalndromicSubsequenceDPBU(string str) {

	memset(dp, 0, sizeof(dp));
	for(int i=0;i<str.size();i++) {
		dp[i][i] = 1;
	}
	for(int l = 2; l <= str.size(); l++) {
		for(int i=0; i <= str.size() - l; i++) {
			int j = i + l - 1;
			if(str[i] == str[j]) {
				dp[i][j] = 2 + dp[i+1][j-1] - (i==j);
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}
	// for(int i=0;i<3;i++) {
	// 	for(int j=0;j<3;j++) {
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return dp[0][str.size()-1];
}

int longestPalndromicSubsequenceDPTD(string str, int l, int r, int val) {
	// if(l==r) {
	// 	return 1;
	// } 
	if(l > r) {
		return val;
	}

	if(dp[l][r] != -1) return dp[l][r];

	if(str[l]==str[r]) {
		return dp[l][r]=longestPalndromicSubsequenceDPTD(str, l+1, r-1, val+2 - (l==r));
	} else {
		return dp[l][r]=max(longestPalndromicSubsequenceDPTD(str, l+1, r, val), longestPalndromicSubsequenceDPTD(str, l, r-1, val));
	}
}

int longestPalndromicSubsequence(string str, int l, int r, int val) {
	
	if(l > r) {
		return val;
	}

	if(str[l]==str[r]) {
		return longestPalndromicSubsequence(str, l+1, r-1, val+2 - (l==r));
	} else {
		return max(longestPalndromicSubsequence(str, l+1, r, val), longestPalndromicSubsequence(str, l, r-1, val));
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	string str;
	cin>>str;
	memset(dp, -1, sizeof(dp));
	// cout<<longestPalndromicSubsequenceDPTD(str, 0, str.size() - 1, 0);
	cout<<longestPalndromicSubsequenceDPBU(str);
	return 0;
}
