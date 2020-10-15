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
#define logarr(arr,a,b)	for(int i=(a);i<=(b);i++) cout<<(arr[i])<<"";cout<<endl;	
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

vi add(vi x, vi y) {
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	ll len = min(x.size(), y.size());
	vi ans;
	ll carry = 0;
	loop(i, 0, len-1) {
		ll val = x[i] + y[i] + carry;
		carry = val/10;
		ans.pb(val%10);
	}
	if(x.size() > len) {
		loop(i, len, x.size() - 1) {
			ll val = x[i] + carry;
			carry = val/10;
			ans.pb(val%10);
		}
	}
	if(y.size() > len) {
		loop(i, len, y.size() - 1) {
			ll val = y[i] + carry;
			carry = val/10;
			ans.pb(val%10);
		}
	}
	while(carry) {
		ans.pb(carry%10);
		carry /= 10;
	}
	// left ??????
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(int argc, char const *argv[]) {
	file_i_o();
	ll t;
	cin>>t;
	while(t--) {
		string a, b;
		cin>>a>>b;
		vi s;
		vi d;
		loop(i, 0, a.size() - 1) {
			s.pb(a[i] - '0');
		}
		loop(i, 0, b.size() - 1) {
			d.pb(b[i] - '0');
		}
		vi sum = add(s, d);
		logarr(sum, 0, sum.size() - 1);
	}
	return 0;
}
