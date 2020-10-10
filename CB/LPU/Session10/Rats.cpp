#include <iostream>
#include <unordered_map>
using namespace std;
int rats(int *arr, int n) {
	unordered_map<int, int> mp;
	int result = 0;
	for(int i=0;i<n;i++) {
		if(arr[i] == 0) {
			result+=1;
			continue;
		}
		if(mp.find(arr[i]) == mp.end()) {
			result+=(arr[i]+1);
			mp[arr[i]] = 0;
		} else {
			mp[arr[i]]++;
			if(mp[arr[i]] == arr[i]) {
				mp.erase(arr[i]);
			}
		}
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<rats(arr, n);
	return 0;
}
