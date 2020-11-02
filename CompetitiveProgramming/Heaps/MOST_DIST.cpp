// Problem Link - https://www.codechef.com/problems/MOSTDIST
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
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
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
	// O(qlogq)
	ll q;
	cin>>q;
	bool *visited = new bool[500005]();
	ll answer = 0;
	ll count = 1;
	priority_queue<pair<ll, ll>> p1, p2, p3, p4; // <value, point number>
	while(q--) {
		char ch;
		ll x, y, n;
		cin>>ch;
		if(ch == '+') {
			// O(logq)
			cin>>x>>y;
			x = x^answer;
			y = y^answer;
			//log(x, y);
			p1.push({x+y, count});
			p2.push({x-y, count});
			p3.push({-x-y, count});
			p4.push({-x+y, count});
			count++;
		} else if (ch == '-') {
			// O(1)
			cin>>n;
			n = n^answer;
			//log(n);
			visited[n] = true;
		} else if (ch == '?') {
			// O(logq)
			cin>>x>>y;
			x = x^answer;
			y = y^answer;
			//log(x, y)
			ll result = INT_MIN;
			while(not p1.empty() and visited[p1.top().ss]) p1.pop(); 
			while(not p2.empty() and visited[p2.top().ss]) p2.pop(); 
			while(not p3.empty() and visited[p3.top().ss]) p3.pop(); 
			while(not p4.empty() and visited[p4.top().ss]) p4.pop(); 

			
			if(not p1.empty()) {
				result = max(result, p1.top().ff - (x+y));
			}
			if(not p2.empty()) {
				result = max(result, p2.top().ff - (x-y));
			}
			if(not p3.empty()) {
				result = max(result, p3.top().ff - (-x-y));
			}
			if(not p4.empty()) {
				result = max(result, p4.top().ff - (-x+y));
			}
			cout<<result<<endl;
			answer = result;
		}
	}
	return 0;
}