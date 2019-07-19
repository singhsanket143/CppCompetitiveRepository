#include <iostream>
using namespace std;

int lcsBU(string s1, string s2) {
	int **dp = new int[s1.size()+1];
	for(int i=0;i<=s1.size();i++) {
		dp[i] = new int[s2.size()+1]();
	}
	for(int i=1;i<=s1.size();i++) {
		for(int j=1;j<=s2.size();j++) {
			if(s1[i-1]==s2[j-1]) {
				dp[i][j] = 1+dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[s1.size()][s2.size()];
}



int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
