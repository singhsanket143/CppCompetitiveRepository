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

int dirx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int diry[] = {1, -1, 2, -2, 2, -2, 1, -1};
double dp[105][30][30];
double KPTD(int n, int k, int i, int j) {
	if(i < 0 or j < 0 or i >= n or j >= n) return 0;
	if(k == 0) return 1;
	if(dp[k][i][j] > -0.9) return dp[k][i][j];
	double ans = 0;
	for(int d = 0; d < 8; d++) {
		ans += ((0.125)*(KPTD(n, k-1, i + dirx[d], j + diry[d])));
	}
	return dp[k][i][j] = ans;
}

double KPBU(int n, int k, int r, int c) {
	dp[k][r][c] = 1.0;
	for(; k > 0; k--) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int d = 0; d < 8; d++) {
					int ni = i + dirx[d];
					int nj = j + diry[d];
					if(ni >= 0 and ni < n and nj >= 0 and nj < n) {
						dp[k-1][ni][nj] += dp[k][i][j]*(0.125);
					}
				}
			}
		}
	}
	double ans = 0.0;
	for(auto row : dp[0]) {
		for(int k = 0; k < n; k++) {
			ans += row[k];
		}
	}
	return ans;
}	

double KPBUO(int n, int k, int r, int c) {
	vector<vector<double > > dp(n, vector<double> (n, 0));
	dp[r][c] = 1.0;
	for(; k > 0; k--) {
		vector<vector<double > > dp2(n, vector<double> (n, 0));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int d = 0; d < 8; d++) {
					int ni = i + dirx[d];
					int nj = j + diry[d];
					if(ni >= 0 and ni < n and nj >= 0 and nj < n) {
						dp2[ni][nj] += dp[i][j]*(0.125);
					}
				}
			}
		}
		dp = dp2;
	}
	double ans = 0.0;
	for(auto row : dp) {
		for(int k = 0; k < n; k++) {
			ans += row[k];
		}
	}
	return ans;
}	

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	memset(dp, -1.0, sizeof dp);
	std::cout<<std::fixed<<std::setprecision(6)<<KPTD(3, 2, 0, 0)<<"\n";
	memset(dp, 0, sizeof dp);
	std::cout<<std::fixed<<std::setprecision(6)<<KPBU(3, 2, 0, 0)<<"\n";
	std::cout<<std::fixed<<std::setprecision(6)<<KPBUO(3, 2, 0, 0)<<"\n";

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
