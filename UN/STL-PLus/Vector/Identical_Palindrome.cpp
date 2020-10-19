// Problem Link - https://codeforces.com/problemset/problem/1343/D
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
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
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


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
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>>k;
		vi arr(n);
		loop(i, 0, n-1) {
			cin>>arr[i];
		}
		vi freq(2*k+2, 0);
		vi sum(2*k+2, 0); // diff vector
		loop(i, 0, (n/2)-1) {
			freq[arr[i] + arr[n-i-1]]++; // possible sum with exact 0 replacement
			sum[min(arr[i],arr[n-i-1]) + 1]++;
			sum[max(arr[i], arr[n-i-1])+k + 1]--;
		}
		loop(i, 1, 2*k+1) {
			sum[i] += sum[i-1];
		}
		ll ans = INT_MAX;
		loop(i, 2, 2*k) {
			ans = min(ans, sum[i] - freq[i] + 2*(n/2 - sum[i]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
