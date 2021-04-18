// Problem Link - https://atcoder.jp/contests/dp/tasks/dp_z
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

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

struct line {
	ll slope;
	ll x_intercept;
	line(ll m, ll k) {
		slope = m;
		x_intercept = k;
	}
	ll valatX(ll x) {
		return slope*x+x_intercept;
	}
	ll x_intersect(line &l2) {
		return ceil(1.0*(l2.x_intercept - x_intercept) / (slope - l2.slope));
	}
};

class Custom {
public:
	deque<pair<line, ll> > dq;
	void insert(line l) {
		if(dq.empty()) {
			dq.pb({l, 0});
			return;
		} 
		while(not dq.empty()) {
			ll x = l.x_intersect(dq.back().ff);
			if(x <= dq.back().ss) {
				dq.pop_back();
			} else {
				break;
			}
		}
		ll x = l.x_intersect(dq.back().ff);
		dq.pb({l, x});
	}
	ll query(ll x) { 
		while(dq.size() > 1) {
			if(dq[1].ss <= x) {
				dq.pop_front();
			} else {
				break;
			}
		}
		return dq[0].ff.valatX(x);
	}
};

ll frog(vector<ll> &h, ll n, ll c) {
	vector<ll> dp(n);
	Custom minDS;
	dp[0] = 0;
	minDS.insert({-2*h[0], h[0]*h[0]}); // inserted line 0
	for(int i = 1; i < n; i++) {
		dp[i] = h[i]*h[i] + c + minDS.query(h[i]);
		minDS.insert({-2*h[i], dp[i] + h[i]*h[i]});
	}
	return dp[n-1];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	ll n, c;
	cin>>n>>c;
	vector<ll> v(n);
	for(int i = 0; i < n; i++) {
		cin>>v[i];
	}
	cout<<frog(v, n, c);
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
