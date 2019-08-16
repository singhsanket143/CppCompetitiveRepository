#include <iostream>
#include <map>
using namespace std;

int largestSubarray(int *arr, int n) {
	int max_len = 0, sum = 0;
	std::map<int, int> presum;
	for(int i=0;i<n;i++) {
		sum+=arr[i];
		if(sum == 0) {
			max_len = i+1;
		}
		if(presum.find(sum)!=presum.end()) {
			max_len = max(max_len, i-presum[sum]);
		} else {
			presum[sum] = i;
		}
	}
	return max_len;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}