#include <iostream>
using namespace std;
bool dp[205][20005];
bool canPartition(vector<int>& nums) {
	int sum = 0;
	for(int i=0;i<nums.size();i++) {
		sum+=nums[i];
	}
	if(sum%2!=0) return false;
	int target = sum/2;
	for(int i=0;i<205;i++) {
		for(int j=0;j<20005;j++) {
			dp[i][j] = false;
		}
	}
	for(int i=0;i<=nums.size();i++) {
		dp[i][0] = true;
	}
	for(int i=1;i<=target;i++) {
		dp[0][i] = false;
	}
	for(int i=1;i<=nums.size();i++) {
		for(int j=1;j<=target;j++) {
			dp[i][j] = dp[i-1][j];
			if(nums[i-1]<=j) {
				dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]];
			}
		}
	}
	return dp[nums.size()][target];

}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
