#include <iostream>
using namespace std;
int kadane(int *arr, int n) {
	int curr_sum = 0;
	int global_max = INT_MIN;

	for(int i=0;i<n;i++) {
		curr_sum+=arr[i];
		if(curr_sum < 0) {
			curr_sum=0;
		}
		if(curr_sum > global_max) {
			global_max = curr_sum;
		}
	}
	return global_max;
}

int maximumSumRec(int **arr, int n, int m) {
	int result = INT_MIN;
	for(int i=0;i<m;i++) {
		int *temp = new int[n]();
		for(int j=i;j<m;j++) {
			// Work
			for(int k = 0; k < n; k++) {
				temp[k] = temp[k] + arr[k][j]; 
			}	
			int kadane_ans = kadane(temp, n);
			if(result < kadane_ans) {
				result = kadane_ans;
			}
		}
		delete [] temp;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i=0;i<n;i++) {
		arr[i] = new int[m];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>arr[i][j];
		}
	}
	cout<<maximumSumRec(arr, n, m);
	return 0;
}
