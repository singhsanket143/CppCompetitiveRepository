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

int skip[10][10];
int helper(vector<bool> &visited, int currDigit, int remainingDigits) {
	if(remainingDigits < 0) return 0;
	if(remainingDigits == 0) return 1;
	visited[currDigit] = true;
	int result = 0;
	for(int i = 1; i <= 9; i++) {
		if(not visited[i] and (skip[currDigit][i] == 0 or visited[skip[currDigit][i]] == true)) {
			result += helper(visited, i, remainingDigits - 1);
		}
	}
	visited[currDigit] = false;
	return result;
}

int countPatterns(int m, int n) {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			skip[i][j] = 0;
		}
	}
	skip[1][3] = skip[3][1] = 2;
	skip[1][7] = skip[7][1] = 4;
	skip[9][3] = skip[3][9] = 6;
	skip[9][7] = skip[7][9] = 8;
	skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
	vector<bool> visited(10, false);
	int result = 0;
	for(int i = m; i <= n; i++) {
		result += helper(visited, 1, i-1)*4; // symmetry for 1,3,7,9
		result += helper(visited, 2, i-1)*4; // symmetry for 1,3,7,9
		result += helper(visited, 5, i-1); // symmetry for 1,3,7,9

	}
	return result;
}

vs allpattern;
int helper(vector<bool> &visited, int currDigit, int remainingDigits, string output) {
	if(remainingDigits < 0) return 0;
	if(remainingDigits == 0) {
		allpattern.push_back(output);
		return 1;
	}
	visited[currDigit] = true;
	int result = 0;
	for(int i = 1; i <= 9; i++) {
		if(not visited[i] and (skip[currDigit][i] == 0 or visited[skip[currDigit][i]] == true)) {
			result += helper(visited, i, remainingDigits - 1, output + to_string(i));
		}
	}
	visited[currDigit] = false;
	return result;
}

int printPatterns(int m, int n, string output) {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			skip[i][j] = 0;
		}
	}
	skip[1][3] = skip[3][1] = 2;
	skip[1][7] = skip[7][1] = 4;
	skip[9][3] = skip[3][9] = 6;
	skip[9][7] = skip[7][9] = 8;
	skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
	vector<bool> visited(10, false);
	int result = 0;
	for(int i = m; i <= n; i++) {
		result += helper(visited, 1, i-1, output + "1"); 
		result += helper(visited, 2, i-1, output + "2");
		result += helper(visited, 3, i-1, output + "3"); 
		result += helper(visited, 4, i-1, output + "4"); 
		result += helper(visited, 5, i-1, output + "5"); 
		result += helper(visited, 6, i-1, output + "6"); 
		result += helper(visited, 7, i-1, output + "7"); 
		result += helper(visited, 8, i-1, output + "8"); 
		result += helper(visited, 9, i-1, output + "9"); 


	}
	return result;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	cout<<countPatterns(4,4)<<endl;
	cout<<printPatterns(4,4, "")<<endl;
	logarr(allpattern, 0, allpattern.size() - 1);
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
