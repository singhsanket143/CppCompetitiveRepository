#include <iostream>
#include <vector>
using namespace std;

int numberOfArithmeticSlices(vector<int> arr) {
	int n=arr.size();
	int *dp = new int[n]();
	for(int i=2;i<n;i++) {
		if(arr[i]-arr[i-1]!=arr[i-1]-arr[i-2]) {
			dp[i] = 0;
		}else {
			dp[i] = 1+dp[i-1];
		}
	}
	int result = 0;
	for(int i=0;i<n;i++) {
		result+=dp[i];
	}
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
