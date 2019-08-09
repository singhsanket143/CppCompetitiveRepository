#include <iostream>
using namespace std;

void permutation(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}

	for(int i=0;i<str.size();i++) {
		char ch = str[i];
		string ros = str.substr(0, i) + str.substr(i+1);
		permutation(ros, osf+ch);
	}
}

int main(int argc, char const *argv[])
{
	permutation("abc", "");
	return 0;
}
