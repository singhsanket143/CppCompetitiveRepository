// Problem Link - https://atcoder.jp/contests/dp/tasks/dp_y
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

ll fact[200005];
ll inv[200005];

ll power(ll val, ll exp) {
	if(exp == 1) return val;
	ll res = power(val, exp/2);
	return (exp & 1) ? ((val*res)%mod*res)%mod : (res*res)% mod;
}

ll inverse(ll val) {
	return power(val, mod-2);
}

ll ncrmodm(int n, int r) {
	return (fact[n] * inv[r]%mod * inv[n-r]%mod)%mod;
}

void process() {
	fact[0] = 1;
	inv[0] = 1;
	for(int i = 1; i <= 200000; i++) {
		fact[i] = (fact[i-1] * i) % mod;
		inv[i] = inverse(fact[i]);
	}
}

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
	return (p1.ff+p1.ss) < (p2.ff+p2.ss);
}

ll pathsBetweenPts(pair<int, int> p1, pair<int, int> p2) {
	if(p1.ff <= p2.ff and p1.ss <= p2.ss) {
		int downsteps = p2.ff - p1.ff;
		int rightsteps = p2.ss - p1.ss;
		return ncrmodm(downsteps + rightsteps, downsteps);
	}
	return 0;
}

ll grid(int h, int w, vector<pair<int, int> > &obs) {
	ll tw = ncrmodm(h+w-2, h-1);
	sort(all(obs), cmp);
	vector<ll> pathToObs; // count of paths from 1,1 to 
	pathToObs.pb(pathsBetweenPts({1,1}, obs[0]));
	for(int i = 1; i < obs.size(); i++) {
		ll paths = pathsBetweenPts({1,1}, obs[i]);
		for(int j = i-1; j >= 0; j--) {
			paths = (mod + paths - (pathToObs[j]*pathsBetweenPts(obs[j], obs[i]))%mod)%mod;
		}
		pathToObs.pb(paths);
	}
	for(int i = 0; i < obs.size(); i++) {
		tw = (mod + tw - (pathToObs[i]*pathsBetweenPts(obs[i], {h, w}))%mod)%mod;
	}	
	return tw;
}


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int h,w,n;
	cin>>h>>w>>n;
	process();
	vector<pair<int, int> > obs(n);
	loop(i, 0, n-1) {
		cin>>obs[i].ff >> obs[i].ss;
	}
	cout<<grid(h, w, obs);
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
