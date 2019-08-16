#include <iostream>
using namespace std;
int kadane(int *arr, int n) {
	int global_max = INT_MIN;
	int curr_sum = 0;
	for (int i = 0; i < n; i++) {
		curr_sum += arr[i];
		if (curr_sum < 0) {
			curr_sum = 0;
		}
		global_max = max(global_max, curr_sum);
	}
	return global_max;
}

int maxSumRec(int **arr, int n, int m) {
	int result = INT_MIN;

	for(int i=0;i<n;i++) {
		int *temp = new int[n]();
		for(int j=i;j<m;j++) {
			// Cumulative sum step
			for(int k=0;k<n;k++) {
				temp[k]+=arr[k][j];
			}
			// call kadane
			int candidate = kadane(temp, n);
			result = max(result, candidate);
		}
		delete [] temp;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int **arr = new int*[n];
	for(int i=0;i<n;i++) {
		arr[i] = new int[n];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>arr[i][j];
		}
	}
	cout<<maxSumRec(arr, n, n);
	return 0;
}
