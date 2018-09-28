#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> arr1, pair<int, int> arr2) {
	return arr1.second > arr2.second; 
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	pair<int, int> arr[n];
	for(int i=0;i<n;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		arr[i] = make_pair(a, b+c);
	}
	sort(arr, arr+n, compare);
	
	long long int ans = arr[0].first + arr[0].second;
	long long int COBOL = arr[0].first;
	for(int i=1;i<n;i++) {
		ans = max(arr[i].first+arr[i].second+COBOL, ans);
		COBOL+=arr[i].first;
	}
	cout<<ans;
	return 0;
}
