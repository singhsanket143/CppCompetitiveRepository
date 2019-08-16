#include <iostream>
using namespace std;

void subsequenceAscii(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}
	char ch=str[0];
	string ros = str.substr(1);

	subsequenceAscii(ros, osf+ch);
	subsequenceAscii(ros, osf);
	subsequenceAscii(ros, osf+to_string((int)ch));
}

int main(int argc, char const *argv[])
{
	/* code */
	subsequenceAscii("abc", "");
	
	return 0;
}