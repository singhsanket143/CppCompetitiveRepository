#include <iostream>
#include <vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
	int n = nums.size();
	int *dp = new int[target+1]();
	dp[0] = 1;
	for(int i = 1; i <= target; i++) {
		for(int j = 0; j < n; j++) {
			if(nums[j] <= i) {
				dp[i] += (unsigned long long int)dp[i-nums[j]]; 
			}
		}
	}
	int result = dp[target];
	delete [] dp;
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
