// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define vi              vector<ll>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int i=(a);i<=(b);i++) cout<<(arr[i])<<" ";	


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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

int main(int argc, char const *argv[]) {
	file_i_o();
	int n, q;
	cin>>n>>q;
	vector<ll> arr(n);
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	vector<ll> idx(n, 0);
	while(q--) {
		int l, r;
		cin>>l>>r;
		l--;r--; // to shift from 1 based indexing to 0 based
		idx[l]++;
		if(r+1 < n) idx[r+1]--;
	}

	// prefix sum
	for(int i = 1; i < n; i++) {
		idx[i] = idx[i] + idx[i-1];
	}

	sort(arr.begin(), arr.end());
	sort(idx.begin(), idx.end());

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans+= (ll)(arr[i]*idx[i]);
	}
	cout<<ans<<endl;
	return 0;
}
