#include <iostream>
using namespace std;

void replacepi(string str, int si, string result) {
	if(si==str.size()-1) {
		result+=str[si];
		cout<<result;
		return;
	}
	if(str[si] == 'p' and str[si+1] == 'i') {
		result+="3.14";
	} else {
		result+=str[si];
	}
	return replacepi(str, si+1, result);
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}