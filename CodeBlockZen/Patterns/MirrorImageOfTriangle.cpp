#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int temp = n;
	for(int i=0;i<=n;i++) {
		for(int j=0;j<temp-i;j++) {
			cout<<" ";
		}
		int count = i;
		while(count>0) {
			cout<<count--;
		}
		while(count<=i) {
			cout<<count++;
		}
		cout<<endl;
	}
	return 0;
}
