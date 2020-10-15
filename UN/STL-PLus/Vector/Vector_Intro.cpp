// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
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
#define logarr(arr,a,b)	for(int i=(a);i<=(b);i++) cout<<(arr[i])<<" ";cout<<endl;	
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
	log(v.size(), v.capacity());
	for(int i =0 ; i < 10; i++) {
		v.push_back(i);
		log(v.size(), v.capacity());
	}

	vector<int> v1(10, -1);
	logarr(v1, 0, v1.size() - 1);
	vector<int> v2 {10, 20, 30};
	vector<int> v3 (v2.begin(), v2.end());
	logarr(v3, 0, v3.size() - 1);
	// vector<int> v4(arr, arr+x); x -> index value

	for(int i = 0; i < v1.size(); i++) {
		cout<<v1[i]<<" ";
	}
	cout<<endl;
	v1[2] = 23;
	for(int i = 0; i < v1.size(); i++) {
		cout<<v1[i]<<" ";
	}
	// for-each
	cout<<endl;

	for(auto el: v1) {
		cout<<el<<" ";
	}
	// two arrays compare ?????
	cout<<((v3 == v2) ? "true" : "false");
	// all true// all false

	vector<bool> arr;
	for(int i = 0 ; i < 5; i++) {
		arr.push_back(true);
	}

	cout<<((arr == vector<bool> (5, true)? "\ntrue" : "\nfalse"));
	v.clear();
	cout<<"\n"<<v.size();
	cout<<(v.empty());
	return 0;
}
