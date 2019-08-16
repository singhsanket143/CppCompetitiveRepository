#include <iostream>
#define ll long long int
using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
	int n = A.size();
	if (n == 0) return 0;
	unordered_map<ll, ll> dp[n];
	ll result = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			ll diff = (ll)((ll)A[i] - (ll)A[j]);
			if (dp[j].find(diff) != dp[j].end()) {
				dp[i][diff] += dp[j][diff] + 1;
				result += dp[j][diff];
			} else
				dp[i][diff]++;
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (auto it = dp[i].begin(); it != dp[i].end(); it++) {
	// 		cout << (*it).first << "->" << (*it).second << ", ";
	// 	}
	// 	cout << endl;
	// }
	return (int)result;
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
