#include <iostream>
#include <set>
#include <unordered_set>
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
int main(int argc, char const *argv[])
{
	file_i_o();
	set<int> s;
	s.insert(10);
	s.emplace(20);
	for(auto &i: s) {
		cout<<i<<endl;
	}

	unordered_set<int> s1;
	s1.insert(10);
	s1.emplace(20);
	for(auto &i: s1) {
		cout<<i<<endl;
	}
	return 0;
}