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

void subsequence(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}
	char ch = str[0];
	string ros = str.substr(1);
	subsequence(ros, osf + ch);
	subsequence(ros, osf);
	subsequence(ros, osf + itos((int)ch));
}

void subsequence2(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}
	char ch = str[0];
	string ros = str.substr(1);
	subsequence2(ros, osf + ch);
	subsequence2(ros, osf);
	subsequence2(ros, osf + to_string((int)ch));
}

int main(int argc, char const *argv[])
{
	subsequence("ac","");
	return 0;
}
