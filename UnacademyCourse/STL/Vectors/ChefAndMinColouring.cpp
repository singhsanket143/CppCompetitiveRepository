
/* By Sanket Singh */
// https://www.codechef.com/NOV19B/problems/CAMC
// Topic: Two Pointer
#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
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
	int t;
	cin>>t;
	while(t--) {
		int m, n;
		cin>>n>>m;
		vector<pair<ll, int> > v(n);
		for(int i = 0; i < n; i++) {
			cin>>v[i].ff;
			v[i].ss = i%m;
		}
		int count = m;
		int right = 0;
		ll ans = INT_MAX;
		sort(v.begin(), v.end());
		vector<int> cnt(n, 0);
		for(int left = 0; left < n; left++) {
			while(right < n and count > 0) {
				count -= cnt[v[right].ss] == 0;
				cnt[v[right].ss]++;
				right++;
			}
			if(count == 0) {
				ans = min(ans, v[right-1].ff - v[left].ff);
			}
			cnt[v[left].ss]--;
			count += cnt[v[left].ss] == 0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
