#include <iostream>
using namespace std;

int sum(int *arr, int i, int j, int n) {
	if(i<=0) {
		return arr[j];
	} else {
		return arr[j] - arr[i-1];
	}
}

int OBST(int *arr, int *freq, int n) {
	int **dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[n]();
	}
	for (int i = 0; i < n; i++) {
		dp[i][i] = freq[i];
	}
	int *cumFreq = new int[n]();
	cumFreq[0] = freq[0];
	for (int i = 0; i < n; i++) {
		cumFreq[i] = cumFreq[i - 1] + freq[i];
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 0; i <= n - l; i++) {
			int j = i + l - 1;
			dp[i][j] = INT_MAX;
			for (int k = i; k <= j; k++) {
				int cost = ((k > i) ? dp[i][k - 1] : 0) + ((k < j) ? dp[k + 1][j] : 0) + sum(cumFreq, i, j, n);
				if (cost < dp[i][j]) {
					dp[i][j] = cost;
				}
			}
		}
	}
	return dp[0][n - 1];

}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *arr = new int[n];
	int *freq = new int[n];
	for (int i = 0; i < n; i++) {
		int el, fre;
		cin >> el >> fre;
		arr[i] = el;
		freq[i] = fre;
	}
	cout << OBST(arr, freq, n) << endl;
	return 0;
}
