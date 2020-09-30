// Problem Link - https://open.kattis.com/problems/pathtracing
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define pb 				push_back
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
	int curr_x = 0, curr_y = 0, start_x = 0, start_y = 0;
	vector<string> v;
	v.pb("*");
	while(getline(cin, str)) {
		if(str == "down") {
			curr_y++;
			if(curr_y >= v.size()) {
				string temp(v[0].size(), ' ');
				v.pb(temp);
			}
		}
		if(str == "up") {
			curr_y--;
			if(curr_y < 0) {
				start_y++;
				curr_y++;
				string temp(v[0].size(), ' ');
				v.insert(v.begin(), temp);
			}
		}
		if(str == "left") {
			curr_x--;
			if(curr_x < 0) {
				start_x++;
				curr_x++;
				for(auto& x: v) {
					x.insert(x.begin(), ' ');
				}
			}
		}
		if(str == "right") {
			curr_x++;
			if(curr_x >= v[0].size()) {
				for(auto& x: v) {
					x.pb(' ');
				}
			}
		}
		v[curr_y][curr_x] = '*';
	}
	v[curr_y][curr_x] = 'E';
	v[start_y][start_x] = 'S';
	for(auto& str: v) {
		str.pb('#');
		str.insert(str.begin(), '#');
	}
	string head_foot(v[0].size(), '#');
	v.pb(head_foot);
	v.insert(v.begin(), head_foot);
	

	for(string str: v) {
		cout<<str<<endl;
	}
	
	return 0;
}
