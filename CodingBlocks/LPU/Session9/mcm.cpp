#include <iostream>
using namespace std;

int mcm(int *arr, int i, int j) {
	if(abs((int)(i - j)) == 1) {
		return 0;
	}

	int result = INT_MAX;
	for(int k=i;k<=j-2;k++) {
		int retval = mcm(arr, i, k+1) + mcm(arr, k+1, j) + arr[i-1]*arr[k]*arr[j-1];
		if(retval < result) result = retval;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<mcm(arr, 1, n);
	return 0;
}
