#include <iostream>
using namespace std;

int maxCoins(vector<int>& nums) {
	if(nums.size() == 0) {
		return 0;
	}
	int **dp = new int*[nums.size()];
	for(int i=0;i<nums.size();i++) {
		dp[i] = new int[nums.size()]();
	}
	for(int l = 1; l <= nums.size(); l++) {
		for(int i = 0; i<=nums.size()-l; i++) {
			int j = i+l-1;
			for(int k=i;k<=j;k++) {
				int leftVal = 1;
				int rightVal = 1;
				if(i>0) {
					leftVal = nums[i-1];
				}
				if(j<nums.size()-1) {
					rightVal = nums[j+1];
				}

				int before = 0, after = 0;
				if(i<k) {
					before = dp[i][k-1];
				}
				if(j>k) {
					after = dp[k+1][j];
				}

				dp[i][j] = max(dp[i][j], before + leftVal*nums[k]*rightVal + after);
			
			}
		}
	} 
	return dp[0][nums.size()-1];    
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
