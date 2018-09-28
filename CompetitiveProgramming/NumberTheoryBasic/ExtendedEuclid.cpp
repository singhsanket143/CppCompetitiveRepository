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

int main(int argc, char const *argv[])
{
	extendedEuclid(18, 30);
	cout<<x<<" "<<y;
	return 0;
}
