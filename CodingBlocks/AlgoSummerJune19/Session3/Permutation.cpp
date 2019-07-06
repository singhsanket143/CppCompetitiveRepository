#include <iostream>
using namespace std;

void permutations(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}
	for(int i=0;i<str.size();i++) {
		char ch = str[i];
		string ros = str.substr(0, i) + str.substr(i+1);
		permutations(ros, osf+ch);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	permutations("abc", "");
	// string str = "abcdefg";
	// cout<<str.substr(0, 3)<<" "<<str.substr(3+1);
	return 0;
}
