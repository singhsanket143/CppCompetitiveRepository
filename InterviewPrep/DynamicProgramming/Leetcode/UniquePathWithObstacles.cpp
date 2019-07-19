#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	if (obstacleGrid[0][0] == 1) return 0;
	if (m == 1 and n == 1 and obstacleGrid[0][0] == 0) return 1;
	if (m == 1 and n == 1 and obstacleGrid[0][0] == 1) return 0;

	int dp[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (obstacleGrid[m - 1][i] == 1) {
			break;
		}
		dp[m - 1][i] = 1;
	}
	for (int i = m - 1; i >= 0; i--) {
		if (obstacleGrid[i][n - 1] == 1) {
			break;
		}
		dp[i][n - 1] = 1;
	}
	for (int i = m - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			int cand1 = 0, cand2 = 0;
			if (obstacleGrid[i + 1][j] != 1) {
				cand1 = dp[i + 1][j];
			}
			if (obstacleGrid[i][j + 1] != 1) {
				cand2 = dp[i][j + 1];
			}
			dp[i][j] = (unsigned int)cand1 + cand2;
		}
	}
	return dp[0][0];
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
