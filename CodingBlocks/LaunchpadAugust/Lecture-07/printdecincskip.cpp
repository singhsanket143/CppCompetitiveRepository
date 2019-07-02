#include <iostream>
using namespace std;

void diskip(int num) {
	if(num<0) {
		return;
	}
	if(num%2!=0) {
		cout<<num<<endl;
	}
	
	// Recursion call
	diskip(num-1);

	if(num%2==0) {
		cout<<num<<endl;
	}
}

int main(int argc, char const *argv[])
{
	diskip(7);
	return 0;
}
