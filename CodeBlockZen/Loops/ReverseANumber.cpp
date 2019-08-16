#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int newnum = 0;
	while(n>0) {
		int rem = n%10;
		newnum = newnum*10+rem;
		n/=10;
	}
	cout<<newnum;
	return 0;
}
