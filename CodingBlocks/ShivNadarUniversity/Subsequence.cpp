#include <iostream>
using namespace std;

void subseq(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}
	char ch = str[0];
	string ros = str.substr(1);
	subseq(ros, osf+ch);
	subseq(ros, osf);
}

int main(int argc, char const *argv[])
{
	subseq("abc", "");
	return 0;
}
