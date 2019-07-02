#include <iostream>
#define ll long long int
using namespace std;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	pair<ll,ll> arr[n];
	for(int i=0;i<n;i++) {
		int a, b;
		cin>>a>>b;
		arr[i].first = a-b;
		arr[i].second = a+b;
	}
	sort(arr, arr+n, cmp);
	int consider = 0;
	int result = 1;
	for(int i=1;i<n;i++) {
		if(arr[i].first >= arr[consider].second) {
			result++;
			consider = i;
		}
	}
	cout<<result;
	return 0;
}
