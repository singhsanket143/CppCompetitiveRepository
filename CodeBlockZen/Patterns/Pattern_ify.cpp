#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n > 0) {
		for(int i=0;i<n;i++) {
			cout<<"*";
		}
		cout<<endl;
		n--;
	}
	return 0;
}
