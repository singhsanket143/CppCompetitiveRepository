#include <iostream>
using namespace std;

void subseq(string str, string osf) {
	// Base case
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}
	// Recursive work and self work

	char ch = str[0];
	string ros = str.substr(1);
	subseq(ros, osf+ch);
	subseq(ros, osf);
}

int main(int argc, char const *argv[])
{
	/* code */
	subseq("abc", "");
	return 0;
}
