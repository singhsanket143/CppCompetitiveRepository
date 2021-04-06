// Problem Link - https://www.hackerrank.com/challenges/prime-xor/problem
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

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	ll max_xor = (1<<13) - 1;
	vector<bool> isPrime(max_xor+5, true);
	isPrime[0] = false;
	isPrime[1] = false;
	loop(i, 2, max_xor) {
		if(isPrime[i]) {
			int j = i * 2;
			while(j <= max_xor) {
				isPrime[j] = false;
				j += i;
			}

		}
	}
	int q;
	cin>>q;
	
	while(q--) {
		vector<int> freq(4505, 0);
		int n;
		cin>>n;
		vector<vector<ll> >dp(2, vector<ll> (max_xor+5, 0));
		loop(i, 0, n-1) {
			int x;
			cin>>x;
			freq[x]++;
		}
		dp[0][0] = 1;
		int flag = 1;
		loop(i, 3500, 4500) {
			loop(j, 0, max_xor) {
				if(freq[i] == 0) {
					dp[flag][j] = dp[1-flag][j];
				} else {
					dp[flag][j] = (dp[1-flag][j]*(freq[i]/2 + 1)%mod + dp[1-flag][j^i]*((freq[i]+1)/2)%mod)%mod;
				}
			}
			flag = 1-flag;
		}
		ll ans = 0;
		loop(j, 0, max_xor) {
			if(isPrime[j]) {
				ans = (ans + dp[1-flag][j])%mod;
			}
		}
		cout<<ans<<endl;
	}
	


	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
