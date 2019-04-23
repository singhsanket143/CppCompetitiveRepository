#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int count = 1;
	int value = 1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<count;j++) {
			cout<<value++;
			if(value>9) value = 1;
		}
		count*=2;
		cout<<endl;
	}
	return 0;
}
