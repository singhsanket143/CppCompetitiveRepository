#include <iostream>
using namespace std;

void subseq(string str, string osf){
	// Base case
	if(str.length()==0) {
		cout<<osf<<endl;
		return;
	}

	// Self work
	char ch = str[0];
	string ros = str.substr(1);
	// Recursive Work
	subseq(ros, osf+ch);
	subseq(ros, osf);
	return;
}

int main(int argc, char const *argv[])
{
	/* code */
	subseq("ab", "");
	return 0;
}
