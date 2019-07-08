#include <iostream>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int>& arr) {
	int n = arr.size();
	if (n == 0) return 0;
	int *dp = new int[n];
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
	}
	int result = 1;
	for (int i = 0; i < n; i++) {
		if (dp[i] > result) result = dp[i];
	}
	return result;
}
void mindeletions(vector<int>& a, int n)
{
	int val = lengthOfLIS(a);
	cout << n - val;
}
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	mindeletions(v, n);
	return 0;
}
