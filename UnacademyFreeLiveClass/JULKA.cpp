// Problem Link - https://www.spoj.com/problems/JULKA/
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

vi divisionBy2(vi x) {
	vi ans;
	// logic
	ll rem = 0; // remainder from prev calc
	loop(i, 0, x.size() - 1) {
		if(rem) {
			rem = rem*10 + x[i];
			ans.pb(rem/2);
			rem = rem%2;
		} else {
			if(x[i] < 2) {
				rem += x[i];
				ans.pb(0);
			} else {
				rem = x[i]%2;
				ans.pb(x[i]/2);
			}
			
		}
	}
	// left ????
	vi result;
	int i = 0;
	while(ans[i] == 0) i++;
	for(; i < ans.size(); i++) {
		result.pb(ans[i]);
	}
	return result;
}

vi sub(vi x, vi y) {
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	vi ans;
	ll len = y.size();
	loop(i, 0, len-1) {
		if(x[i] < y[i]) {
			x[i+1]--;
			ans.pb(10+x[i] - y[i]);
		} else {	
			ans.pb(x[i] - y[i]);
		}
	}
	// need to something?
	if(x.size() > len) {
		loop(i, len, x.size() - 1) {
			if(x[i] < 0) {
				x[i+1]--;
				ans.pb(10*x[i]);
			} else {
				ans.pb(x[i]);
			}
		}
	}
	reverse(ans.begin(), ans.end());

	// some zeroes that need to removed????
	vi result;
	int i = 0;
	while(ans[i] == 0) i++;
	for(; i < ans.size(); i++) {
		result.pb(ans[i]);
	}
	return result;
}

int main(int argc, char const *argv[]) {
	file_i_o();
	//int t = 2;
	loop(i, 0, 9) {
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
		vi temp_sum = add(s, d);
		//logarr(temp_sum, 0, temp_sum.size() - 1);
		vi div = divisionBy2(temp_sum); // Value A
		vi diff = sub(s, div); // value B

		logarr(div, 0, div.size() - 1);
		logarr(diff, 0, diff.size() - 1);
	}
	return 0;
}
