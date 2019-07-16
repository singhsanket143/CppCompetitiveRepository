#include <iostream>
using namespace std;

int fpair(int n) {
	if(n==0) return 1;
	if(n==1) return 1;
	if(n==2) return 2;
	// Assumption
	int r1 = fpair(n-1);
	int r2 = fpair(n-2);

	// Self work
	return r1+(n-1)*r2;
}

int main(int argc, char const *argv[])
{
	cout<<fpair(4);
	return 0;
}
