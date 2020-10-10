#include <iostream>
using namespace std;

void codesOfString(string str, string osf) {
	if (str.size() == 0 ) { // Base case
		cout << osf << endl;
		return;
	}
	if (str.size() == 1) {
		int ch = str[0] - '0';
		codesOfString(str.substr(1), osf + (char)(96 + ch));
	} else {
		int one = str[0] - '0';
		int two = stoi(str.substr(0, 2));
		if (two <= 26) {
			codesOfString(str.substr(2), osf + (char)(96 + two));
		}
		codesOfString(str.substr(1), osf + (char)(96 + one)); // definite
	}
}

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	codesOfString(str, "");
	return 0;
}
