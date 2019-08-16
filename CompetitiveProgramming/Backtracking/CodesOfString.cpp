#include <iostream>
using namespace std;

void printCodes(string str, string osf, char *arr) {
		if (str.size() == 0) {
			cout<<(osf)<<endl;
			return;
		}
		int one = str[0] - '0';
		int two = 0;
		if (str.size() > 1)
			two = stoi(str.substr(0, 2));
		else
			two = 0;
		if (two < 27 and str.size() > 1) {
			printCodes(str.substr(1), osf + arr[one - 1], arr);
			printCodes(str.substr(2), osf + arr[two - 1], arr);
		} else {
			printCodes(str.substr(1), osf + arr[one - 1], arr);
		}
}

int main(int argc, char const *argv[])
{
	/* code */
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f','g','h','i', 'j', 'k',
		 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
		 'w', 'x', 'y', 'z' };
		 printCodes("1123", "", arr);
	return 0;
}
