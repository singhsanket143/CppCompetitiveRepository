#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutiveSequence(int *arr, int n) { // O(n)
	unordered_set<int> s;
	for(int i=0;i<n;i++) {
		s.insert(arr[i]);
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		if(s.find(arr[i] - 1) != s.end()) {
			continue;
		} else {
			int count = 0;
			int x = arr[i]; // Left Boundary
			while(s.find(x) != s.end()) {
				count++;
				x++;
			}
			ans = max(ans, count);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	int ans = longestConsecutiveSequence(arr, n);
	cout<<ans<<endl;
	return 0;
}