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

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<kadane(arr, n);
	return 0;
}





