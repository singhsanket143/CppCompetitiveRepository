#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

bool isValid(ll *arr, ll n, ll ans, ll no_of_cows) {
	ll last_pos = arr[0];
	int current_cows = 1;
	for(int i=1;i<n;i++) {
		if(arr[i] - last_pos >= ans) {
			current_cows++;
			last_pos = arr[i];
		}
		if(current_cows == no_of_cows) {
			return true;
		}
	}
	if(current_cows == no_of_cows) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--) {
		ll n, c;
		cin>>n>>c;
		ll ans = 0;
		ll *arr = new ll[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		sort(arr, arr+n);
		ll start = arr[0];
		ll end = arr[n-1];
		while(start<=end) {
			ll mid = (start+end)/2;
			if(isValid(arr, n, mid, c)) {
				ans = mid;
				start = mid+1;
			} else {
				end = mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
