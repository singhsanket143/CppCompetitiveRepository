#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=1;i<=2*n-1;i++) {
		for(int j=1;j<=2*n-1;j++) {
			if(i == j or j==2*n-i) {
				if(i<n)
					cout<<i;
				else
					cout<<2*n-i;
			} else {
				cout<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}
