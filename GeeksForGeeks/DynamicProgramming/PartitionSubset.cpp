#include <iostream>
using namespace std;

bool partitionSubset(int *arr, int n, int target) {
	bool dp[n+1][target+1];
	memset(dp, false, sizeof(dp));
	dp[0][0]=true;
	for(int i=1;i<=target;i++) {
		dp[0][i] = false;
	}
	for(int i=1;i<=n;i++) {
		dp[i][0] = true;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=target;j++) {
			if(j>arr[i-1]) {
				dp[i][j] = dp[i-1][j];
			}
			if(j<=arr[i-1]) {
				dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
			}
		}
	}
	return dp[n][target];
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	int sum = 0;
	for(int i=0;i<n;i++) {
		sum+=arr[i];
	}
	if(sum%2!=0) cout<<"NO";
	else if(partitionSubset(arr, n, sum/2)) cout<<"YES";
	else cout<<"NO";
	return 0;
}
