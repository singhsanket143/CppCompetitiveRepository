#include <iostream>
using namespace std;

void subsequence(string str, string osf) {
	// Base
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}

	// Assumption
	char ch = str[0]; // First character
	string ros = str.substr(1);
	// Self work
	subsequence(ros, osf+ch);
	subsequence(ros, osf);
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	subsequence(str, "");
	return 0;
}
