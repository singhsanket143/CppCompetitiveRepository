#include <iostream>
using namespace std;
bool isScramble(string s1, string s2) {
	int n = s1.size();
	int dp[n][n][n + 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= n; k++) {
				dp[i][j][k] = false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s1[i] == s2[j]) {
				dp[i][j][1] = true;
			}
		}
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 0; i <= n - l; i++) {
			for (int j = 0; j <= n - l; j++) {
				dp[i][j][l] = false;
				for (int k = 1; k < l; k++) {
					if ((dp[i][j][k] and dp[i + k][j + k][l - k]) or (dp[i][j + l - k][k] and dp[i + k][j][l - k])) {
						dp[i][j][l] = true;
						break;
					}
				}
			}
		}
	}
	return dp[0][0][n];
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
