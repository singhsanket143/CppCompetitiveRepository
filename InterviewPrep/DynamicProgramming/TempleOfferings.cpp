#include <iostream>
using namespace std;

int minOfferings(int *arr, int n) {
	int *dp1 = new int[n];
	int *dp2 = new int[n];
	dp1[0] = 1;
	for(int i=1;i<n;i++) {
		if(arr[i]>arr[i-1]) {
			dp1[i] = 1+dp1[i-1];
		} else {
			dp1[i] = 1;
		}
	}
	dp2[n-1] = 1;
	for(int i=n-2;i>=0;i--) {
		if(arr[i]>arr[i+1]) {
			dp2[i] = 1+dp2[i+1];
		} else {
			dp2[i] = 1;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans+=max(dp1[i], dp2[i]);
	}
	return ans;

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<minOfferings(arr, n)<<endl;
	return 0;
}
