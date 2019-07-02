#include <iostream>
using namespace std;

int binary(int n) {
	// Base case
	if(n==1) return 2;
	if(n==2) return 3;
	return binary(n-1) + binary(n-2);
}

int main(int argc, char const *argv[])
{
	/* code */
	cout<<binary(4);
	return 0;
}
