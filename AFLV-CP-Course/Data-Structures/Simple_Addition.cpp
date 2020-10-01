// Problem Link - https://open.kattis.com/problems/simpleaddition
/* By Sanket Singh */
#include<bits/stdc++.h>
#include<cstdlib>
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
	string x, y, new_x, new_y;
	cin>>x>>y;
	// cout<<x<<endl;
	// cout<<y<<endl;
	string result = "";
	int len = max(x.size(), y.size());
	if(len == x.size()) {
		int extra = len - y.size();
		string prepend(extra, '0');
		y = prepend + y;
	} else {
		int extra = len - x.size();
		string prepend(extra, '0');
		x = prepend+x;
	}
	int carry = 0;
	// cout<<x<<endl;
	// cout<<y<<endl;
	for(int i = (len - 1); i >= 0; i--) {
		int a = x[i] - '0';
		int b = y[i] - '0';
		int sum = a+b+carry;
		//cout<<sum<<"\n";
		carry = sum / 10;
		result += to_string(sum%10);
	}
	if(carry != 0)
		result += to_string(carry);
	//cout<<carry<<endl;
	reverse(result.begin(), result.end());
	cout<<result;
	return 0;
}
