#include <iostream>
using namespace std;
// str2 is the target
int editDistance(string str1, string str2) {
	int dp[str1.size()+1][str2.size()+1];
	dp[0][0] = 0;
	for(int i=1;i<=str1.size();i++) dp[i][0] = dp[i-1][0] + 1;
	for(int i=1;i<=str2.size();i++) dp[0][i] = dp[0][i-1] + 1;
	for(int i=1;i<=str1.size();i++) {
		for(int j=1;j<=str2.size();j++) {
			int replace = 1+dp[i-1][j-1];
			int delet = 1+dp[i-1][j];
			int insert = 1+dp[i][j-1];
			dp[i][j] = min(replace, min(insert, delet));
		}
	}
	return dp[str1.size()][str2.size()];
}

int main(int argc, char const *argv[])
{
	

	return 0;
}
