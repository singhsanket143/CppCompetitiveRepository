#include <iostream>
using namespace std;

void helloString(string str, string osf) {
	if(str.size() == 1) {
		osf = osf + str[0];
		cout<<osf<<endl;
		return;
	}
	char ch1 = str[0];
	char ch2 = str[1];
	string ros = str.substr(1);
	if(ch1 == ch2) {
		helloString(ros, osf + ch1 + '*');
	} else {
		helloString(ros, osf + ch1);
	}

}

int main(int argc, char const *argv[])
{
	/* code */
	helloString("helll", "");
	return 0;
}
