#include <iostream>
using namespace std;

void replacepi(string str, string osf) {
	// Base case
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}


	if(str[0] != 'p') {
		char ch = str[0];
		replacepi(str.substr(1), osf+ch);
	} else if(str[0] == 'p') {

		if(str.size() >= 2 and str[1] == 'i') {
			replacepi(str.substr(2), osf+"3.14");
		} else {
			char ch=str[0];
			replacepi(str.substr(1), osf+ch);
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	string str;
	cin>>str;
	replacepi(str, "");
	return 0;
}