// Problem Link - https://www.spoj.com/problems/NOTATRI/
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define ump				unordered_map
#define mp 				map
#define ff 				first
#define ss 				second
#define loop(i,n) 		for(int i=0;i<(n);i++)
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
	int n;
	cin>>n;
	while(true) {
		vector<int> arr(n, 0);
		loop(i, n) {
			cin>>arr[i];
		}
		sort(arr.begin(), arr.end());
		ll ans = 0;
		loop(i, n) {
			for(int j = i+1; j < n-1; j++) {
				auto upper = upper_bound(arr.begin(), arr.end(), arr[i] + arr[j]);
				ans += (arr.end() - upper);
			}
		}
		cout<<ans<<endl;
		cin>>n;
		if(n==0) break;
	}
	return 0;
}
