#include <iostream>
#include <set>
using namespace std;

bool isPalindrome(string str) {
	int lo=0, hi=str.size()-1;
	while(lo<=hi) {
		if(str[lo]!=str[hi]) {
			return false;
		}
		lo++;
		hi--;
	}
	return true;
}

void check(set<int> &s) {
	for(int i=100;i<1000;i++) {
		for(int j=100;j<1000;j++) {
			if(isPalindrome(to_string(i*j))) {
				s.insert(i*j);
			}
		}
	} 
	
}

int main(int argc, char const *argv[])
{
	cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	int t;
	cin>>t;
	set<int> s;
	check(s);
	while(t--) {
		int n;
		cin>>n;

		cout<<*(--s.lower_bound(n))<<endl;
	}
	return 0;
}
