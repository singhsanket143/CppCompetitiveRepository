#include <iostream>
using namespace std;

int factorial(int n) {
	if(n==0) {
		return 1;
	}

	return n*factorial(n-1);
}

int main(int argc, char const *argv[])
{
	cout<<factorial(5);
	return 0;
}
