// Problem Link - 
/* By Sanket Singh */
// #include<bits/stdc++.h>
#include<iostream>
#include <algorithm>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
// #define ll 				long long int
// #define ld				long double
// #define mod             1000000007
// #define inf             1e18
// #define endl			"\n"
// #define pb 				emplace_back
// #define vi              vector<ll>
// #define vs				vector<string>
// #define pii             pair<ll,ll>
// #define ump				unordered_map
// #define mp 				map
// #define pq_max          priority_queue<ll>
// #define pq_min          priority_queue<ll,vi,greater<ll> >
// #define ff 				first
// #define ss 				second
// #define mid(l,r)        (l+(r-l)/2)
// #define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
// #define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
// #define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// #define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
// #define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
// vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) {
// 	cout << *it << " = " << a << endl;
// 	err(++it, args...);
// }
// //typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// void file_i_o()
// {
//     ios_base::sync_with_stdio(0); 
//     cin.tie(0); 
//     cout.tie(0);
// 	#ifndef ONLINE_JUDGE
// 	    freopen("input.txt", "r", stdin);
// 	    freopen("output.txt", "w", stdout);
// 	#endif
// }

int main(int argc, char const *argv[]) {
	file_i_o();
	vi arr {1,2,3};
	// auto it = lower_bound(arr.begin(), arr.end(), 6);
	// auto it2 = upper_bound(arr.begin(), arr.end(), 6);
	// log(it - arr.begin());
	// log(it2 - arr.begin());
	// it = lower_bound(arr.begin(), arr.end(), 4);
	// it2 = upper_bound(arr.begin(), arr.end(), 4);
	// log(it - arr.begin());
	// log(it2 - arr.begin());
	// it = lower_bound(arr.begin(), arr.end(), 1);
	// it2 = upper_bound(arr.begin(), arr.end(), 1);
	// log(it - arr.begin());
	// log(it2 - arr.begin());
	// it = lower_bound(arr.begin(), arr.end(), 9);
	// it2 = upper_bound(arr.begin(), arr.end(), 9);
	// log(it - arr.begin());
	// log(it2 - arr.begin());

	// next_permutation(first, last)

	// do {
	// 	logarr(arr, 0, 2);
	// } while(next_permutation(arr.begin(), arr.end()));

	// vi arr1 {3,2,1};

	// do {
	// 	logarr(arr1, 0, 2);
	// } while(prev_permutation(arr1.begin(), arr1.end()));

	// ld x = 1.0/2.0;
	// cout<<x<<endl;
	// cout.precision(5);
	// cout<<x<<endl;
	// cout<<fixed<<setprecision(5)<<x<<endl;
	// printf("%0.5Lf", x);
	cout<<gcd(10, 6);
	return 0;
}
