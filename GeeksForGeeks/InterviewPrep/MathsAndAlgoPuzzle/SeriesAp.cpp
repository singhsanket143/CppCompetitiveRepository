#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int a, b, n;
		cin>>a>>b;
		cin>>n;
		int d = b-a;
		cout<<a + (n-1)*d <<endl;
	}
	return 0;
}
