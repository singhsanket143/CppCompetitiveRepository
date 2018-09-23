#include <iostream>
using namespace std;

int lcs(string str1, string str2, int i, int j) {
	if(i>=str1.size() or j>=str2.size()) {
		return 0;
	}
	if(str1[i] == str2[j]) {
		return 1 + lcs(str1, str2, i+1, j+1);
	} else {
		return max(lcs(str1,str2,i+1, j), lcs(str1,str2,i, j+1));
	}
}

int main(int argc, char const *argv[])
{
	string str1="abcde";
	string str2="axbycud";
	cout<<lcs(str1, str2, 0, 0);
	return 0;
}
