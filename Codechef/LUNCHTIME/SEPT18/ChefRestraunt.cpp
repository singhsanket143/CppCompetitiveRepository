#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pp pair<int,int>
bool cmp(const pp &l,const pp &r) {
    return l.first < r.first;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		ll n, m;
		cin>>n>>m;
		pair<ll, ll > arr[n];
		for(ll i=0;i<n;i++) {
			ll a,b;
			cin>>a>>b;
			arr[i] = make_pair(a,b);
		}
		sort(arr, arr+n, cmp);
		for(ll i=0;i<m;i++) {
			ll q;
			cin>>q;
			int pos = ((lower_bound(arr, arr+n,pp(q,0) , cmp)) - arr);
			if(pos >= n) {
				if(arr[n-1].second>q) {
					cout<<"0"<<"\n";
				} else {
					cout<<"-1"<<endl;
				}
				continue;
			}
			if(arr[pos].first == q) {
				cout<<"0"<<"\n";
			} else if(arr[pos].first > q) {
				if(pos>0 and arr[pos-1].second > q and arr[pos-1].first < q) {
					cout<<"0"<<"\n";
				} else {
					cout<<abs(arr[pos].first - q)<<endl;
				}
			}
		}
	}
	return 0;
}
