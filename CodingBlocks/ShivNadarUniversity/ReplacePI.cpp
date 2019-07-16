#include <iostream>
using namespace std;

void replacePi(string str, string osf) {
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}

	if(str.size() == 1) {
		replacePi(str.substr(1), osf+str[0]);
	} else {
		if(str[0] == 'p' and str[1] == 'i') {
			replacePi(str.substr(2), osf+"3.14");
		} else {
			replacePi(str.substr(1), osf+str[0]);
		}
	}

}

int main(int argc, char const *argv[])
{
	replacePi("p", "");
	return 0;
}
