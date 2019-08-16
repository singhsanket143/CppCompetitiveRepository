#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i=0;
	while(i*i<=n) {
		i++;
	}
	cout<<--i;
	return 0;
}
