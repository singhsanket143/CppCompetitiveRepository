#include <iostream>
using namespace std;

int friends(int n) {
	// Base case
	if(n==0 or n==1) return 1;
	if(n==2) return 2;

	return friends(n-1) + ((n-1)*friends(n-2));
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<friends(n);
	return 0;
}
