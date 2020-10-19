// Problem Link - https://cses.fi/problemset/task/1746
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
	int n, m;
	cin>>n>>m;
	vi arr(n);
	loop(i, 0, n-1) {
		cin>>arr[i];
	}
	vector<vector<ll> > dp(m+1, vector<ll> (n, 0));
	loop(i, 0, n-1) {
		if(i == 0) {
			if(arr[i] != 0) dp[arr[i]][i] = 1;
			else {
				loop(j, 1, m) {
					dp[j][i] = 1;
				}
			}
			continue;
		}

		if(arr[i] != 0) {
			dp[arr[i]][i] = (((arr[i]-1 > 0)?dp[arr[i]-1][i-1]:0)%mod + dp[arr[i]][i-1]%mod + ((arr[i]+1 <= m)?dp[arr[i]+1][i-1]:0)%mod);
		} 
		else {
			loop(j, 1, m) {
				dp[j][i] = dp[j][i-1];
				if(j > 1) dp[j][i] = (dp[j][i]%mod + dp[j-1][i-1]%mod);
				if(j < m) dp[j][i] = (dp[j][i]%mod + dp[j+1][i-1]%mod);
				dp[j][i] %= mod;
			}
		}
	}
	// loop(i, 0, m) {
	// 	logarr(dp[i], 0, n-1);
	// }
	if(arr[n-1] != 0) cout<< dp[arr[n-1]][n-1]%mod;
	else {
		ll ans = 0;
		loop(j, 1, m) {
			ans = (ans%mod + dp[j][n-1]%mod)%mod;
		}
		cout<<ans;
	}

	return 0;
}
