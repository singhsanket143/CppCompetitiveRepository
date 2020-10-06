// Problem Link - https://codeforces.com/contest/177/problem/D2
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define vi              vector<ll>
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
	int n, m, c;
	cin>>n>>m>>c;
	vi msg(n);
	vi diff(n);
	loop(i, 0, n-1) {
		cin>>msg[i];
	}
	loop(i, 0, m-1) {
		int x;
		cin>>x;
		diff[i] += x;
		if(n - m + i + 1 < n) {
			diff[n - m + i + 1] -= x;
		}
	}
	
	loop(i, 1, n-1) {
		diff[i] = diff[i-1] + diff[i];
	}
	loop(i, 0, n-1) {
		msg[i] = (msg[i] + diff[i])%c;
	}
	loop(i, 0, n-1) {
		cout<<msg[i]<<" ";
	}
	return 0;
}
