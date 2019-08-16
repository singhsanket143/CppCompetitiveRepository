#include <iostream>
#include <unordered_map>
#define ll long long int
using namespace std;

int colorFul(int n) {
	string str = to_string(n);
	unordered_map<ll, bool> mp;
	for(int i=0;i<str.length();i++) {
		ll mul=1;
		for(int j=i;j<str.length();j++) {
			mul*=(ll)(str[j]-'0');
			if(mp.find(mul) != mp.end()) {
				return 0;
			} else {
				mp[mul] = true;
			}
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
