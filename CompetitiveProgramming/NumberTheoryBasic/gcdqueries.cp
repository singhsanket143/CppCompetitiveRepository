//https://www.codechef.com/problems/GCDQ
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n, q;
	    cin>>n>>q;
	    vector<int> arr(n);
	    for(int i = 0; i < n; i++) {
	        cin>>arr[i];
	    }
	    vector<int> prefix(n);
	    vector<int> suffix(n);
	    prefix[0] = arr[0];
	    suffix[n-1] = arr[n-1];
	    for(int i = 1; i < n; i++) {
	        prefix[i] = __gcd(prefix[i-1], arr[i]);
	    }
	    for(int i = n-2; i >= 0; i--) {
	        suffix[i] = __gcd(suffix[i+1], arr[i]);
	    }
	    while(q--) {
	        int l,r ;
	        cin>>l>>r;
	        l--;r--;
	        if(l == 0) cout<<suffix[r+1]<<"\n";
	        else if (r == n-1) cout<<prefix[l-1]<<"\n";
	        else cout<<__gcd(prefix[l-1], suffix[r+1])<<"\n";
	    }
	}
	return 0;
}
