#include <iostream>
using namespace std;

int fastPower(int a, int b) {
	if(b == 0) {
		return 1;
	}

	int result = fastPower(a, b/2);
	result *= a;
	if(b % 2 != 0) {
		return result * a;
	}
	return result;
}

int main(int argc, char const *argv[])
{
		
	cout<<fastPower(2,4)<<endl;
	return 0;
}
