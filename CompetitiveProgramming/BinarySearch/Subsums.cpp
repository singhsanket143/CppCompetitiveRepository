// Problem Link - https://www.spoj.com/problems/SUBSUMS/
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define ump				unordered_map
#define mp 				map
#define ff 				first
#define ss 				second
#define pb 				push_back
#define loop(i,n) 		for(int i=0;i<(n);i++)
#define DEBUG(x) 		cout << '>' << #x << ':' << x << endl;
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

void generateSubsets(int start, int size, vector<ll>& arr, vector<ll>& result) {
	loop(mask, (1 << size)) {
		ll sum = 0;
		loop(i, size) {
			if(mask & (1 << i)) sum+=arr[i+start];
		}
		result.pb(sum);
	}
}

int main(int argc, char const *argv[]) {
	file_i_o();
	ll n, a, b, ans = 0;
	cin>>n>>a>>b;
	vector<ll> arr(n);
	loop(i, n) {
		cin>>arr[i];
	}
	vector<ll> first_half;
	vector<ll> second_half;
	generateSubsets(0, n/2, arr, first_half);
	generateSubsets(n/2, n&1?n/2+1:n/2, arr, second_half);
	sort(second_half.begin(), second_half.end());
	loop(i, first_half.size()) {
		ll lo = lower_bound(second_half.begin(), second_half.end(), a-first_half[i]) - second_half.begin();
		ll hi = upper_bound(second_half.begin(), second_half.end(), b-first_half[i]) - second_half.begin();
		ans += (hi - lo);
	}
	cout<<ans<<endl;
	return 0;
}
