#include <iostream>
using namespace std;

int modExp(int a, int b, int c) {
	int result = 1;
	int value = a;
	while(b!=0) {
		if((b&1) == 1) {
			result = ((result%c) * (value%c))%c;
		}
		b=b>>1;
		value = ((value%c) * (value%c))%c;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin>>a>>b>>c;
	cout<<modExp(a, b, c); 
	return 0;
}
