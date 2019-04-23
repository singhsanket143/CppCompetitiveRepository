#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char ch = 'A';
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			cout<<ch;
		}
		ch++;
		cout<<endl;
	}
	return 0;
}
