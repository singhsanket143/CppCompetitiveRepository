#include <iostream>
using namespace std;

int dp[300][300];

int minSquare(int m, int n) {
	if(m==n) return 1;
	if(dp[m][n]) {
		return dp[m][n];
	}
	int hmin = INT_MAX;
	int vmin = INT_MAX;
	for(int i = 1; i <= m/2; i++) {
		hmin = min(hmin, minSquare(i, n) + minSquare(m-i, n));
	}
	for(int i = 1; i <= n/2; i++) {
		vmin = min(vmin, minSquare(m, i) + minSquare(m, n-i));
	}

	return dp[m][n] = min(hmin, vmin);
}

int main(int argc, char const *argv[])
{
	for(int i = 0; i < 300; i++)
		for(int j = 0; j < 300; j++)
			dp[i][j] = 0;
	cout<<minSquare(30, 35);
	return 0;
}
