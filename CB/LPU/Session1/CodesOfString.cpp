#include <iostream>
using namespace std;

void codes(string str, string osf, char *arr) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}



	int one = str[0] - '0';
	int two = 0;
	if(str.size()>=2) {
		two = stoi(str.substr(0, 2));
		// work
		codes(str.substr(1), osf+arr[one], arr);
		if(two<=26) {
			codes(str.substr(2), osf+arr[two], arr);	
		}
	} else {
		codes(str.substr(1), osf+arr[one], arr);
	}
}

int main(int argc, char const *argv[])
{
	char mapping[27] = {'#', 'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	string str;
	cin>>str;
	codes(str, "", mapping);
	return 0;
}
