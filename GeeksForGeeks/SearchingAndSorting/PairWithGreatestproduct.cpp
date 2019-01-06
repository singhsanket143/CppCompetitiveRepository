#include <iostream>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
int findMaxProductPair(int *arr, int n) {
	unordered_map<int, int> mp;
	for(int i=0;i<n;i++) {
		mp[arr[i]]++;
	}
	sort(arr, arr+n);
	for(int i=n-1;i>1;i++) {
		for(int j=0;j<i and arr[j]<=sqrt(arr[i]);j++) {
			if(arr[i]%arr[j]==0) {
				int result = arr[i]/arr[j];
				if(result != arr[j] and mp[arr[j]]>0) {
					return arr[i];
				}
				else if(result == arr[j] and mp[arr[j]]>1) {
					return arr[i];
				}
			}
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<findMaxProductPair(arr, n);
	return 0;
}
