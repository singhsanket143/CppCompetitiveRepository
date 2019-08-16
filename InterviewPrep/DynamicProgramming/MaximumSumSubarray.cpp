#include <iostream>
using namespace std;

int maxSumSub(int *inp, int n) {
	int result = -INT_MAX;
	for (int i = 0; i < n; i++) {
		int sum = inp[i];
		result = max(sum, result);
		for (int j = i + 1; j < n; j++) {
			sum += inp[j];
			result = max(sum, result);
		}
	}
	return result;
}

int maxSubArraySum(int a[], int size)
{
	int max_so_far = a[0];
	int curr_max = a[0];

	for (int i = 1; i < size; i++)
	{
		curr_max = max(a[i], curr_max + a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
