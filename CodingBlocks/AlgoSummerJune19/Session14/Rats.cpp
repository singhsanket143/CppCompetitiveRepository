#include <iostream>
#include <unordered_map>
using namespace std;

int numrats(int *arr, int n) {
	unordered_map<int, int> mp;
	int ans=0;
	for(int i=0;i<n;i++) {
		if(arr[i]==0) {
			ans+=1;
			continue;
		}
		if(mp.find(arr[i])==mp.end()) {
			mp[arr[i]]=0;
			ans+=(arr[i]+1);
		} else {
			mp[arr[i]]++;
			if(mp[arr[i]] == arr[i]) {
				mp.erase(arr[i]);
			}
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<numrats(arr, n);
	return 0;
}
