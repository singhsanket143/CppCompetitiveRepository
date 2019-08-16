#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int i=0;
	if(str[i]=='9') {
		i++;
	}
	for(;str[i]!='\0';i++) {
		int digit = str[i] - '0';
		if(digit>=5) {
			digit = 9 - digit;
			str[i] = digit + '0';
		}
	}
	cout<<str<<endl;
	return 0;
}
