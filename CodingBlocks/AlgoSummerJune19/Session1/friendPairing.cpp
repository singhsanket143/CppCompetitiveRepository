#include <iostream>
using namespace std;

int frnd(int n) {
	if(n==0) return 1;
	if(n==1) return 1;
	if(n==2) return 2;

	return frnd(n-1) + ((n-1)*frnd(n-2));
}

int main(int argc, char const *argv[])
{
	/* code */
	cout<<frnd(3);
	return 0;
}
