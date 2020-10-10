#include <iostream>
using namespace std;

void replacePi(string str, string osf) {
	// Base case
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}
	if(str.size() == 1) {
		cout<<osf+str<<endl;
		return;
	}

	if(str[0] == 'p' and str[1] == 'i') {
		string ros = str.substr(2);
		replacePi(ros, osf+"3.14");
	} else {
		char ch = str[0];
		string ros = str.substr(1);
		replacePi(ros, osf+ch);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	replacePi("xppixp", "");
	return 0;
}
