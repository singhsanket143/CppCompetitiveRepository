// Problem Link - https://open.kattis.com/problems/cold
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
	ll n, x, count = 0;
	scanf("%lld", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &x);
		if (x < 0) {
			count++;
		}
	}
	printf("%lld", count);
	return 0;
}
