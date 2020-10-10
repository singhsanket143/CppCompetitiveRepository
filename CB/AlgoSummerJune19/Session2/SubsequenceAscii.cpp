#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string itos(int i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

void subseq(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);
	subseq(ros, osf+ch);
	subseq(ros, osf);
	subseq(ros, osf + to_string((int)ch));
}

int main(int argc, char const *argv[])
{
	string str = "abc";
	subseq(str, "");
	cout<<(char)(48);
	return 0;
}
