// Problem Link - https://codeforces.com/contest/1324/problem/D
/* By Sanket Singh */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll> >, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
	int n;
	pbds arr;
	cin>>n;
	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];
	loop(i, 0, n-1) {
		cin>>a[i];
	}
	loop(i, 0, n-1) {
		cin>>b[i];
	}
	loop(i, 0, n-1) {
		c[i] = a[i] - b[i];
	}
	ll ans = 0;
	loop(i, 0, n-1) {
		if(i == 0) {
			arr.insert({c[i], i});
			continue;
		}
		ans += (arr.size() - arr.order_of_key({-c[i], 1e9}));
		arr.insert({c[i], i});
	}
	cout<<ans;
	return 0;
}
