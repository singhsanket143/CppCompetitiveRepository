#include <iostream>
#include <map>
using namespace std;

void largestSubarray(int *arr, int n) {
	int max_len = 0, sum = 0, si = 0, ei = 0;
	std::map<int, int> presum;
	for(int i=0;i<n;i++) {
		sum+=arr[i];
		if(sum == 0) {
			max_len = i+1;
			si = 0;
			ei = i;
		}
		if(presum.find(sum)!=presum.end()) {
			int temp = max_len;
			max_len = max(max_len, i-presum[sum]);
			if(max_len>temp) {
				si = presum[sum]+1;
				ei = i;
			}
		} else {
			presum[sum] = i;
		}
	}
    if(max_len == 0) {
        cout<<"None"<<endl;
    } else {
	    cout<<si<<" "<<ei<<endl;
    }
	return ;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int arr[n];
		int temp[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
			if(arr[i]==0) {
				temp[i] = -1;
			} else {
				temp[i] = arr[i];
			}
		}
		largestSubarray(temp,n);
	}
	return 0;
}