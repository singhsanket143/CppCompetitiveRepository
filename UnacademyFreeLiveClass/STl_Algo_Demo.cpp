// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
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
#define logarr(arr,a,b)	for(int i=(a);i<=(b);i++) cout<<(arr[i])<<" ";	
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
	vector<int> v;
	looprev(i, 2, 0) {
		v.pb(i);
	}
	// //logarr(v, 0, 5);
	// do {
	// 	logarr(v, 0, 2);
	// 	cout<<endl;
	// } while (next_permutation(v.begin(), v.end()));

	// cout<<"--";
	do {
		logarr(v, 0, 2);
		cout<<endl;
	} while (prev_permutation(v.begin(), v.end()));


	vector<int> v1;
	loop(i, 1, 10) {
		v1.pb(i);
	}
	logarr(v1, 0, 9);
	cout<<endl;
	vector<int> v2 {1, 2, 2, 4, 4, 4, 4, 5, 6};
	auto it = lower_bound(v2.begin(), v2.end(), 9); // logn // first index where value is not less than the given value


	cout<<(it - v2.begin())<<endl;

	auto it1 = upper_bound(v2.begin(), v2.end(), 4);
	cout<<(it1 - v2.begin())<<endl;


	cout<<__gcd(6, 10);
	return 0;
}
