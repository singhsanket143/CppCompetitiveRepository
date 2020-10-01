// Problem Link - https://open.kattis.com/problems/backspace
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
	string str;
	cin>>str;
	stack<char> st;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '<' and !st.empty()) st.pop();
		else st.push(str[i]);
	}
	string result = "";
	while(!st.empty()) {
		result += st.top();
		st.pop();
	}
	reverse(result.begin(), result.end());
	cout<<result;
	return 0;
}
