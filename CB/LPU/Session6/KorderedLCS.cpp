#include <iostream>
using namespace std;

int dp[2005][2005][8];

int KOrderedLCS(int n, int m, int *arr1, int *arr2, int k, int i, int j) {
	if(i == n or j == m) {
		return 0;
	}
	if(dp[i][j][k] != -1) return dp[i][j][k];

	int ans;
	if(arr1[i] == arr2[j]) {
		ans = 1+KOrderedLCS(n, m, arr1, arr2, k, i+1, j+1);
		dp[i][j][k] = ans;
		return ans;
	} else {
		int call1 = KOrderedLCS(n, m, arr1, arr2, k, i+1, j);
		int call2 = KOrderedLCS(n, m, arr1, arr2, k, i, j+1);
		int call3 = -1;
		if(k>0) {
			call3 = 1+KOrderedLCS(n, m, arr1, arr2, k-1, i+1, j+1);
		}
		ans = max(call1, max(call2, call3));
		dp[i][j][k] = ans;
		return ans;

	}
}

int main(int argc, char const *argv[])
{
	int n, m, k;
	cin>>n>>m>>k;
	int *arr1 = new int[n];
	int *arr2 = new int[m];
	for(int i=0;i<n;i++) {
		cin>>arr1[i];
	}
	for(int i=0;i<m;i++) {
		cin>>arr2[i];
	}
	for(int i=0;i<2005;i++) {
		for(int j=0;j<2005;j++) {
			for(int k=0;k<8;k++) {
				dp[i][j][k]=-1;
			}
		}
	}
	cout<<KOrderedLCS(n, m, arr1, arr2, k, 0, 0);
	return 0;
}