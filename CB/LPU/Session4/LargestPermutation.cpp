#include <iostream>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n>>k;
	unordered_map<int, int> mp;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		mp[arr[i]] = i;
	}
	for(int i=n;i>=1;i--) {
		if(k==0) break;
		if(mp[i] == n-i) continue;
		int correct = n-i;
		int current = mp[i];



		
		swap(arr[correct], arr[current]);
		mp[i] = correct;
		mp[arr[current]] = current;
		k--;
	}
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}
