#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

bool check(ll arr[], int n, ll mid, ll c) {
	ll result = 1;
	ll last_pos = arr[0];
	for(int i=1;i<n;i++) {
		if(arr[i] - last_pos >= mid) {
			result++;
			last_pos = arr[i];
		}
		if(result == c) {
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		ll c;
		cin>>n>>c;
		ll arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
      	sort(arr, arr+n);
		ll lo = 0, hi = arr[n-1] - arr[0];
		ll ans = -1;
		while(lo<=hi) {
			ll mid = (lo+hi)/2;
			if(check(arr, n, mid, c)) {
				ans = mid;
				lo = mid+1;
			} else {
				hi = mid-1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
