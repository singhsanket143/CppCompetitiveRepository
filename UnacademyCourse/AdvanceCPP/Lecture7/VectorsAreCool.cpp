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

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	vector<int> v;
	for(int i = 0; i < 5; i++) {
		v.emplace_back(i);
	}
	cout<<v[2]<<endl; // never throws runtime exception, behaviour can be undefined here
	cout<<v.at(3)<<endl; // throws exception
	cout<<v.front()<<" "<<v.back()<<endl;
	cout<<v.size()<<" "<<v.capacity()<<" "<<v.max_size()<<endl;


	for(int e : v) {
		cout<<e<<" ";
	}
	cout<<endl;
	for(auto e : v) {
		cout<<e<<" ";
	}
	cout<<endl;
	cout<<v.empty()<<endl;
	// v.clear();
	cout<<v.size()<<" "<<v.capacity()<<endl;
	v[0] = 10;
	vector<int>::iterator it = v.begin();
	cout<<*it<<endl;
	it = v.end();
	cout<<*it<<endl;

	for(it = v.begin(); it != v.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<*(v.end() - 1)<<endl;

	// erase expects an iterator
	v.erase(v.begin() + 2); // erase elements from between the vector
	for(it = v.begin(); it != v.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<endl;

	// range delete [first, last)
	v.erase(v.begin(), v.begin()+2); // erase elements from between the vector
	for(it = v.begin(); it != v.end(); it++) {
		cout<<*it<<" ";
	}

	v.pop_back(); // removes the ;ast element in O(1)


	vector<int> v1 {1,2,3,41,5};
	vector<int> v2 {1,2,3,4,5};

	cout<<(v1 == v2)<<endl; // compare vectors
	vector<int> v3(5, 1);
	cout<<(v3 == vector<int> (5, 1))<<endl;

	auto i = v3.insert(v3.begin()+1, 2); // insert function takes an iterator for position and the element and performs insertion in between, and also returns the iterator to the inserted position
	cout<<*i<<endl;
	for(it = v3.begin(); it != v3.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<endl;
	sort(v3.begin(), v3.end());
	for(it = v3.begin(); it != v3.end(); it++) {
		cout<<*it<<" ";
	}
	// cout<<i<<endl;

	int x = 10;
	int *ptr = &x;
	cout<<ptr<<endl;


	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
