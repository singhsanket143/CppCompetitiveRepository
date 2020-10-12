// Problem Link - https://www.codechef.com/UAPRAC/problems/RNDWAEZ
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

ld find_dist(ld x1, ld x2, ld y1, ld y2) {
	return sqrtl((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(int argc, char const *argv[]) {
	file_i_o();
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<ld> x(n);
		vector<ld> y(n);
		loop(i, 0, n-1) {
			cin>>x[i]>>y[i];
		}
		ld qx, qy, rx, ry;
		cin>>qx>>qy>>rx>>ry;
		ld max_dist = find_dist(qx, rx, qy, ry);
		int idx = -1;
		loop(i, 0, n-1) {
			if(x[i] == rx and y[i] == ry) {
				idx = i;
				break;
			}
		}
		if(idx != -1) {
			x.erase(x.begin() + idx);
			y.erase(y.begin() + idx);
			n--;
		}
		vector<int> perm(n);
		loop(i, 0, n-1) {
			perm[i] = i;
		}
		ld ans = 0.0;
		int count = 0; // count of permutations
		ld valid_dist_count = 0.0;
		// setprecision
		// cout.precision

		// fixed
		do {
			loop(i, 1, n-1) {
				ans += find_dist(x[perm[i]], x[perm[i-1]], y[perm[i]], y[perm[i-1]]);
			}
			ans += find_dist(x[perm[0]], rx, y[perm[0]], ry); // R-p1

			if(ans <= max_dist) {
				valid_dist_count++;
			}
			count++;
			ans = 0.0;
		} while (next_permutation(perm.begin(), perm.end()));
		ld result = valid_dist_count/count;
		//printf("%0.8Lf", )
		cout<<fixed<<setprecision(8)<<result<<endl;

	}
	return 0;
}
