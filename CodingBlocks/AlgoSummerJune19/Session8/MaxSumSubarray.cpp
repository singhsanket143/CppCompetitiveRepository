#include <iostream>
using namespace std;

int kadane(int *arr, int n) {
	int global_max = INT_MIN;
	int curr_sum = 0;
	for(int i=0;i<n;i++) {
		curr_sum+=arr[i];
		if(curr_sum < 0) {
			curr_sum = 0;
		}
		global_max = max(global_max, curr_sum);
	}
	return global_max;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
