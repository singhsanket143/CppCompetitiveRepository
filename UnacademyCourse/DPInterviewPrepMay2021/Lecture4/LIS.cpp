// Problem Link - 
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

int lis(vector<int> &arr) {
	// O(n^2)
	int n = arr.size();
	vector<int> dp(n, 1);
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[j] < arr[i])
				dp[i] = max(dp[i], 1 + dp[j]);
		}
	}
	return *(std::max_element(all(dp)));
}

int lisOP(vector<int> &arr) { // O(nlogn)
	int n = arr.size();
	vector<int> dp(n, 1);
	map<int, int> mp; // sorted map <element, dp>
	mp[arr[0]] = 1;
	int ans = dp[0];
	for(int i = 1; i < n; i++) {
		auto it = mp.lower_bound(arr[i]+1); // first val > x
		if(it != mp.begin()) {
			it--;
			dp[i] += it->second;
		}
		mp[arr[i]] = dp[i];
		it = mp.upper_bound(arr[i]); // first value in the container greater than x
		while(it != mp.end() and it->second <= dp[i]) {
			auto t = it;
			t++;
			mp.erase(it);
			it = t;
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin>>n;
	vector<int> arr(n);
	loop(i, 0, n-1) {
		cin>>arr[i];
	}
	std::cout<<lis(arr)<<"\n";
	std::cout<<lisOP(arr)<<"\n";

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
