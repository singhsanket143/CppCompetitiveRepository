#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	if(n > 2 and (n-2)%2==0) {
		cout<<"YES";
	} else {
		cout<<"NO";
	}
	return 0;
}
