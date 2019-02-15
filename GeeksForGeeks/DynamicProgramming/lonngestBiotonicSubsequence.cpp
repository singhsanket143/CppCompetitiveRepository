#include <iostream>
using namespace std;

int longestBiotonicSub(int *arr, int n) {
	int *lis = new int[n];
	int *lds = new int[n];
	for(int i=0;i<n;i++) {
		lis[i] = 1;
	}
	for(int i=0;i<n;i++) {
		lds[i] = 1;
	}
	for(int i=1;i<n;i++) {
		for(int j=0;j<i;j++) {
			if(arr[i]>arr[j] and lis[i]<lis[j]+1) lis[i] = lis[j]+1;
		}
	}
	for(int i=n-2;i>=0;i--) {
		for(int j=n-1;j>i;j--) {
			if(arr[i]>arr[j] and lds[i]<lds[j]+1) lds[i] = lds[j]+1;
		}
	}
	int max = lis[0] + lds[0] - 1;
	
	for(int i=1;i<n;i++) {
		if(max<lis[i]+lds[i]-1) {
			max = lis[i]+lds[i]-1;
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<longestBiotonicSub(arr, n)<<endl;
    }
	return 0;
}
