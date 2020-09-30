
/* By Sanket Singh */
//https://codeforces.com/contest/276/problem/C
// Topic: Difference Arrays
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void fio()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[]) {
	fio();
	int n, q;
	cin>>n>>q;
	vector<ll> v(n, 0);
	vector<ll> query(n, 0);
	for(int i = 0; i < n; i++) {
		cin>>v[i];
	}
	while(q--) {
		int x, y;
		cin>>x>>y;
		x--;y--;
		if(x < 0) return 0;
		query[x]++;
		if(y + 1 <= n-1) query[y+1]--; 
	}
	for(int i = 1; i < n; i++) {
		query[i] = query[i] + query[i-1];
	}
	sort(v.begin(), v.end());
	sort(query.begin(), query.end());
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans = ans + (v[i]*query[i]);
	}
	cout<<ans;
	return 0;
}
