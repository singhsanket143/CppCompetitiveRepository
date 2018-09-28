#include <iostream>
using namespace std;

int x, y, gcd;
void extendedEuclid(int a, int b) {
	if(b==0) {
		x=1;
		y=0;
		gcd = a;
		return;
	}
	extendedEuclid(b, a%b);
	int cX = y;
	int cY = x - (a/b)*y;

	x = cX;
	y = cY;
}

int hcf(int a, int b) {
	if(b==0) {
		return a;
	}
	return hcf(b, a%b);
}

int getModuloInverse(int a, int m) {
	if(hcf(a,m) == 1) {
		extendedEuclid(a, m);
		return (x+m)%m;
	} else {
		return -1;
	}
}

int main(int argc, char const *argv[])
{
	return 0;
}
