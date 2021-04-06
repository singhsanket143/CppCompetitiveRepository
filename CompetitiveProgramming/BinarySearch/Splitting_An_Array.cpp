// Problem Link - https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B
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
#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

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
	int n, k;
	cin>>n>>k;
	ll *arr = new ll[n];
	loop(i, 0, n-1) {
		cin>>arr[i];
	}
	ll lo = 1, hi = 1e15;
	ll result = 1;
	while(lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		int count_seg = 1;
		ll sum = 0, ans = 0;
		for(int i = 0; i < n; i++) {
			if(sum + arr[i] > mid) {
				ans = max(ans, sum);
				sum = 0;
				count_seg++;
				if(count_seg > k) break;
			}
			sum += arr[i];
		}
		ans = max(ans, sum);
		if(count_seg == k) {
				result = ans;
			}
		if(count_seg > k) {
			lo = mid + 1;
		} else {
			
			hi = mid - 1;
		}
	}
	cout<<result;
	return 0;
}
