// Problem Link - https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define DEBUG(x) 		cout << '>' << #x << ':' << x << endl;
using namespace std;

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
	setprecision(9);
	ll n;
	cin>>n;
	ll *pos = new ll[n];
	ll *vel = new ll[n];
	for(int i = 0; i < n; i++) {
		cin>>pos[i];
		cin>>vel[i];
	}
	cout.precision(9);
	long double lo = 1e-10, hi = 1e10;
	while(hi - lo > 1e-7) {
		long double mid_t = lo + (hi - lo) / 2;
		long double main_lower_limit = -1 * numeric_limits<double>::max(), main_upper_limit = numeric_limits<double>::max();
		for(int i = 0; i < n; i++) {
			long double lower_limit = (long double)(pos[i] - (long double)(mid_t * vel[i]));
			long double upper_limit = (long double)(pos[i] + (long double)(mid_t * vel[i]));
			main_lower_limit = max(main_lower_limit, lower_limit);
			main_upper_limit = min(main_upper_limit, upper_limit);
		}
		if(main_lower_limit <= main_upper_limit) {
			hi = mid_t;
		} else {
			lo = mid_t;
		}
	}
	cout<<hi<<endl;
	return 0;
}
