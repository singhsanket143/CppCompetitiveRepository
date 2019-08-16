#include <iostream>
using namespace std;

int twins(string str) {
	if(str.size() < 3) {
		return 0;
	}
	if(str[0] == str[2]) {
		return 1+twins(str.substr(1));
	} else {
		return twins(str.substr(1));
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	string str;
	cin>>str;
	cout<<twins(str);
	return 0;
}
