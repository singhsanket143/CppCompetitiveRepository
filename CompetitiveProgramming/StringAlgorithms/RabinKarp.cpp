#include <bits/stdc++.h>
#define ll long long int
#define prime 101
using namespace std;

ll createHashValue(string str, int n) {
	ll result = 0;
	for(int i=0;i<n;i++) {
		result += (ll)(str[i]*(ll)pow(prime, i));
	}
	return result;
}

ll recalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patLength) {
	ll newHash = oldHash - str[oldIndex];
	newHash = newHash/prime;
	newHash += (ll)(str[newIndex]*(ll)pow(prime, patLength-1));
	return newHash;
}

bool checkEqual(string str1, int start1, int end1, string str2, int start2, int end2) {
	if(end1-start1!=end2-start2) {
		return false;
	}
	while(start1<=end1 and start2 <= end2) {
		if(str1[start1] != str2[start2]) {
			return false;
		}
		start1++;
		start2++;
	}
	return true;
}

int main(int argc, char const *argv[])
{

	string str = "TusharRoy";
	string pat = "Tus";
	long patHash = createHashValue(pat, pat.length());
	long strHash = createHashValue(str, pat.length());
	cout<<patHash<<" "<<strHash<<endl;
	for(int i=0;i<=str.length()-pat.length();i++) {
		if(patHash == strHash and checkEqual(str, i, i+pat.length()-1, pat, 0, pat.length()-1)) {
			cout<<i<<endl;
			return 0;
		}
		cout<<strHash<<endl;
		if(i<str.length()-pat.length())
			strHash = recalculateHash(str, i, i+pat.length(), strHash, pat.length());
	}
	cout<<"-1";
	return 0;
}
