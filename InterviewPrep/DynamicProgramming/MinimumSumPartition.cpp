#include <iostream>
using namespace std;
bool dp[205][20005];
int findMinSumPartition(vector<int>& nums) {
	int sum = 0;
	for(int i=0;i<nums.size();i++) {
		sum+=nums[i];
	}
	for(int i=0;i<205;i++) {
		for(int j=0;j<20005;j++) {
			dp[i][j] = false;
		}
	}
	for(int i=0;i<=nums.size();i++) {
		dp[i][0] = true;
	}
	for(int i=1;i<=sum;i++) {
		dp[0][i] = false;
	}
	for(int i=1;i<=nums.size();i++) {
		for(int j=1;j<=sum;j++) {
			dp[i][j] = dp[i-1][j];
			if(nums[i-1]<=j) {
				dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]];
			}
		}
	}
	int diff = INT_MAX;
	for(int j=sum/2;j>=0;j--) {
		if(dp[nums.size()][j] == true) {
			diff = sum - 2*j;
			break;
		}
	}
	return diff;

}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
