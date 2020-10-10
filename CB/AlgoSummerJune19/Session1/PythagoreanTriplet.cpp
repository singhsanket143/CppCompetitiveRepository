#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x;
	cin>>x;
	if(x%2==0) { // x is even
		cout<<x<<" "<<((x*x)/4)-1<<" "<<((x*x)/4)+1;
	} else { // x is odd
		cout<<x<<" "<<(x*x - 1)/2<<" "<<(x*x + 1)/2;
	}
	return 0;
}
