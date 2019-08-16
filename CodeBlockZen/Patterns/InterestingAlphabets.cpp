#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		char ch = 'A'+n-1;
		ch = ch -i + 1;
		for(int j=1;j<=i;j++) {
			cout<<ch++;
		}
		cout<<endl;
	}
	return 0;
}
