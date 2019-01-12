#include <iostream>
using namespace std;


int stockSelling(int *arr,int n, int k) {

	int dp[k+1][n+1];
	for(int i=0;i<k;i++) {
		dp[i][0] = 0;
	}
	for(int i=0;i<n;i++) {
		dp[0][i] = 0;
	}
	for(int i=0;i<k;i++) {
		for(int j=0;j<n;j++) {
		
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>>k;
		int arr[n];
		for(int i = 0; i < n; i++) {
			cin>>arr[i];
		}
	}
	return 0;
}
