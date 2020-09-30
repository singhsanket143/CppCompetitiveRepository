// Problem Link - https://open.kattis.com/problems/server
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
	//file_i_o();
	int n, t, x;
	cin>>n>>t;
	int count = 0;
	bool flag = false;
	while(n--) {
		cin>>x;
		if(x > t) {
			cout<<count;
			flag = true;
			break;
		}
		count++;
		t -= x;
	}
	if(!flag) {
	    cout<<count;
	}
	return 0;
}
