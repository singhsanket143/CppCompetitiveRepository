#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	std::unordered_map<int, int> mp;
	while(t--) {
		int n,k;
		cin>>n>>k;
		mp.clear();
		int *arr = new int[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		sort(arr, arr+n, greater<int>());
		int val = arr[k-1];
		for(int i=0;i<n;i++) {
			if(mp.find(arr[i])!=mp.end()) {
				mp[arr[i]] = mp.at(arr[i])+1;
			} else {
				mp[arr[i]] = 1;
			}
		}
		long long int result = 0;
		for(auto itr = mp.begin(); itr != mp.end(); itr++) {
			if(itr->first >= val) {
				result+=itr->second;
			}
		}
		cout<<result<<endl;
        delete [] arr;
	}
	return 0;
}
