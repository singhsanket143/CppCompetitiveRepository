#include <iostream>
using namespace std;

void print(int n, string osf) {
	if(osf.size() == n) {
		cout<<osf<<endl;
		return;
	}

	for(int i=1;i<=9;i++) {
		if(osf.size() == 0) {
			print(n, osf+to_string(i));
		} else {
			if(osf[osf.size()-1]-'0' < i) {
				print(n, osf+to_string(i));
			}
		}
	}
}





int main(int argc, char const *argv[])
{
	// print(3,"");
	char ch = '9';
	cout<<ch-'0';
	return 0;
}
