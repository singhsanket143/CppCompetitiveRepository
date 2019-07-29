#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;



bool check(ll *arr, ll n, ll candidate, ll cows) {
	ll last_pos = arr[0];
	ll placed_cows = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] - last_pos >= candidate) {
			placed_cows++;
			last_pos = arr[i];
		}
		if (placed_cows == cows) {
			return true;
		}
	}
	if (placed_cows == cows) {
		return true;
	}
	else {
		return false;
	}
}

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--) {
		ll n, cows;
		cin>>n>>cows;
		ll *arr = new ll[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		sort(arr, arr+n);
		ll lo = arr[0], hi = arr[n-1];
		int ans = 0;
		while(lo<=hi) {
			ll mid = (lo+hi)/2;
			if(check(arr, n, mid, cows) == true) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout<<ans<<endl;
		delete [] arr;
	}
	return 0;
}
