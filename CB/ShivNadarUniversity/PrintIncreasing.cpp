#include <iostream>
using namespace std;

void pinc(int n) {
	if(n==0) {
		return;
	}
	pinc(n-1);
	cout<<n;
}

int main(int argc, char const *argv[])
{
	pinc(5);
	return 0;
}
