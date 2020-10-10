#include <iostream>
using namespace std;

void lexico(int n, int start) {
	if(start > n) {
		return;
	}
	if(start == n) {
		cout<<start<<endl;
		return;
	}

	cout<<start<<endl;
	for(int i = (start == 0)?1:0; i <= 9; i++) {
		lexico(n, 10*start+i);
	}
}

int main(int argc, char const *argv[])
{
	lexico(13, 0);
	return 0;
}
