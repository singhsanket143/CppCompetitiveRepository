#include <iostream>
using namespace std;

double knightProbability(int N, int k, int r, int c) {
	double **dp = new double*[N];
	for (int i = 0; i < N; i++) {
		dp[i] = new double[N]();
	}
	int nr[8] = { -2, -1, -2, -1, 2, 1, 2, 1};
	int nc[8] = { -1, -2, 1, 2, -1, -2, 1, 2};
	dp[r][c] = 1;
	while (k--) {
		double **dp2 = new double*[N];
		for (int i = 0; i < N; i++) {
			dp2[i] = new double[N]();
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dp[i][j] == 0) continue;
				for (int l = 0; l < 8; l++) {
					int cr = i + nr[l];
					int cc = j + nc[l];
					if (cr >= 0 and cc >= 0 and cr < N and cc < N) {
						dp2[cr][cc] += dp[i][j] / 8.0;
					}
				}
			}
		}
		dp = dp2;
	}
	double ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += dp[i][j];
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n, k, r, c;
	cin >> n >> k >> r >> c;
	cout<<knightProbability(n, k, r, c);
	return 0;
}
