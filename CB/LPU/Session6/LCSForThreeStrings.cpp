#include <iostream>
using namespace std;
int dp[100][100][100];
int lcs(string s1, string s2, string s3) {
	if(s1.size() == 0 or s2.size()==0 or s3.size()==0) {
		return 0;
	}
	if(s1[0] == s2[0] and s1[0]==s3[0]) {
		return 1+lcs(s1.substr(1), s2.substr(1), s3.substr(1));
	} else {
		return max(lcs(s1.substr(1), s2, s3), max(lcs(s1, s2.substr(1), s3), lcs(s1, s2, s3.substr(1))));
	}
}

int lcsTD(string s1, string s2, string s3) {
	if(s1.size() == 0 or s2.size()==0 or s3.size()==0) {
		return 0;
	}

	if(dp[s1.size()][s2.size()][s3.size()]!=-1) {
		return dp[s1.size()][s2.size()][s3.size()];
	}
	int ans;
	if(s1[0] == s2[0] and s1[0]==s3[0]) {
		ans = 1+lcsTD(s1.substr(1), s2.substr(1), s3.substr(1));
	} else {
		ans = max(lcsTD(s1.substr(1), s2, s3), max(lcsTD(s1, s2.substr(1), s3), lcsTD(s1, s2, s3.substr(1))));
	}
	dp[s1.size()][s2.size()][s3.size()] = ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	string s1, s2, s3;
	cin>>s1>>s2>>s3;
	for(int i=0;i<100;i++) {
		for(int j=0;j<100;j++) {
			for(int k=0;k<100;k++){
				dp[i][j][k]=-1;
			}
			
		}
	}
	cout<<lcsTD(s1, s2, s3);
	
	return 0;
}
