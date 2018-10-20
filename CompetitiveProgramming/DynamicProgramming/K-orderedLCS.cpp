#include <iostream>
#define ll long long int
using namespace std;

ll dp[2005][2005][8];

ll korderedLCS(int *a, int *b, int n, int m, int i, int j, int k) {
	if(n == i or m == j) {
		return 0;
	}
	if(dp[i][j][k] != -1) {
		return dp[i][j][k];
	}
	ll res = 0;
	if(a[i] == b[j]) {
		res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k);
	} else {
		if(k>0) {
			res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k-1);
		}
		res = max(res, korderedLCS(a, b, n, m, i+1, j, k));
		res = max(res, korderedLCS(a, b, n, m, i, j+1, k));
	}
	dp[i][j][k] = res;
	return res;

}

int main(int argc, char const *argv[])
{
	
	int n, m, k;
	cin>>n>>m>>k;
	int a[n];
	int b[m];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<m;i++) {
		cin>>b[i];
	}
	for(int i=0;i<2005;i++) {
		for(int j=0;j<2005;j++) {
			for(int m=0;m<8;m++) {
				dp[i][j][m] = -1;
			}
		}
	}
	cout<< korderedLCS(a, b, n, m, 0, 0, k);
	return 0;
}
