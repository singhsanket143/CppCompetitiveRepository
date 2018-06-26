#include <iostream>
using namespace std;

int fastPowerBitMask(int a, int b) {

	int result = 1;
	while(b > 0) {
		if(b & 1) {
			result *= a;
		}
		a = a * a;
		b = b>>1;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	cout<<fastPowerBitMask(3, 1)<<endl;		
	return 0;
}
