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

ld find_dist(ld x1, ld x2, ld y1, ld y2) {
	return sqrtl((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t;
	cin>>t;
	while(t--) {
		int n;
		std::cin>>n;
		std::vector<ld> x(n);
		std::vector<ld> y(n);
		loop(i, 0, n-1) {
			std::cin>>x[i]>>y[i];
		}

		ld qx, qy, rx, ry;
		std::cin>>qx>>qy>>rx>>ry;

		ld max_dist = find_dist(qx, rx, qy, ry);
		int idx = -1;
		ld permcount = 0.0;
		loop(i, 0, n-1) {
			if(x[i] == rx and y[i] == ry) {
				idx = i;
				break;
			}
		}
		if(idx != -1) {
			n--;
			x.erase(x.begin() + idx);
			y.erase(y.begin() + idx);
		}

		vi perm(n); // 0,1,2,3,4,5,..
		loop(i, 0, n-1) perm[i] = i;

		ld valid_dist_count = 0.0;
		ld ans = 0.0;
		cout.precision(8);
		do {
			loop(i, 1, n-1) {
				ans += find_dist(x[perm[i]], x[perm[i-1]], y[perm[i]], y[perm[i-1]]);
			}
			ans += find_dist(rx, x[perm[0]], ry, y[perm[0]]);

			if(ans <= max_dist) valid_dist_count++;
			permcount++;
			ans = 0.0;
		} while(std::next_permutation(all(perm)));

		ld result = valid_dist_count/permcount;
		std::cout<<std::fixed<<result<<"\n";
	}


	// next_permutation works with containers having bidirectional iterators
	// comparison for customn object is done based on either < operator or cmp function
	// int arr[] = {1,2,3,4};

	// std::next_permutation(arr, arr+4);
	// std::next_permutation(arr, arr+4);
	// log(arr[0], arr[1], arr[2], arr[3]);

	// std::string s = "abc";
	// std::next_permutation(all(s));
	// cout<<s<<endl;




	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
