#include <iostream>
#include "math.h"
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a = 5*n*n-4;
	int b = 5*n*n+4;

	int sqrt1 = sqrt(a);
	int sqrt2 = sqrt(b);

	if(sqrt1*sqrt1 == a or sqrt2*sqrt2 == b) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
	return 0;
}
