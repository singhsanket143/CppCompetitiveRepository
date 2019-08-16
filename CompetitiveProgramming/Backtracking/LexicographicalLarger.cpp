#include <iostream>
#include <string>
using namespace std;

void lexicoLarger(string str, string osf, bool flag) {
	if(str.size() == 0) {
		cout << osf << endl;
		return;
	}
	for(int i = 0; i < str.size(); i++) {
		string ros = str.substr(0, i) + str.substr(i+1);
		char ch = str[i];
		if(flag) {
			lexicoLarger(ros, osf+ch, flag);
		} else {
			if(str[i] >= str[0]) {
				lexicoLarger(ros, osf+ch, flag or ch > str[0]);
			} else {
				// No call
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	lexicoLarger("bcad", "", false);
	return 0;
}
