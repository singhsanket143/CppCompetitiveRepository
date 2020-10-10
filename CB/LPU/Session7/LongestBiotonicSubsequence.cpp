#include <iostream>
using namespace std;

int lbs(int *arr, int n) {
	int *lis = new int[n];
	int *lds = new int[n];
	int *lbs = new int[n];
	for(int i=0;i<n;i++) {
		lis[i] = 1;
		lds[i] = 1;
	}
	for(int i=1;i<n;i++) {
		for(int j=0;j<i;j++) {
			if(arr[i]> arr[j]) {
				lis[i] = max(lis[i], 1+lis[j]);
			}
		}
	}
	for(int i=n-2;i>=0;i--) {
		for(int j=n-1;j>i;j--) {
			if(arr[i] > arr[j]) {
				lds[i] = max(lds[i], lds[j]+1);
			}
		}
	}
	for(int i=0;i<n;i++) {
		lbs[i] = lis[i]+lds[i]-1;
	}
	int result = -1;
	for(int i=0;i<n;i++) {
		if(lbs[i] > result) result=lbs[i];
	}
	return result;
}


int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<lbs(arr, n);
	return 0;
}
