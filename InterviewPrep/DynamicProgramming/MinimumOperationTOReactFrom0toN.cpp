#include<iostream>
#include<climits>
using namespace std;

void minOperations(int n) {
	// Write your code here
	int *dp = new int[n + 1]();
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; i++) {
		int cand1 = dp[i - 1] + 1;
		int cand2 = INT_MAX;
		if (i % 2 == 0) {
			cand2 = dp[i / 2] + 1;
		}
		dp[i] = min(cand1, cand2);
	}
	cout << dp[n];
}

int main(int argc, char**argv) {
	int n;
	cin >> n;
	minOperations(n);
}