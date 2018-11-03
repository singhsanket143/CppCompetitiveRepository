#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.second < b.second;
}

int main(int argc, char const *argv[])
{
		int n, a, b;
		cin>>n;
		pair<ll, ll> arr[n];
		for(int i=0;i<n;i++) {
			cin>>a>>b;
			arr[i] = make_pair(a-b, a+b);
		}
		sort(arr, arr+n, cmp);
		// for(int i=0;i<n;i++) {
		// 	cout<<arr[i].first<<" "<<arr[i].second<<endl;
		// }
		int ans = 1, chosen = 0;
		for(int i=1;i<n;i++) {
			if(arr[i].first>=arr[chosen].second) {
				ans++;
				chosen = i;
			}
		}
		cout<<n-ans<<endl;
	return 0;
}
