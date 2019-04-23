#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int temp=n;
	while(n>0){
		char ch = 'A';
		for(int i=0;i<temp-n;i++) {
			cout<<" ";
		}
		for(int i=1;i<=n;i++) {
			cout<<ch;
			ch++;
		}
		ch--;
		for(int i=1;i<=n;i++) {
			cout<<ch;
			ch--;
		}
		cout<<endl;
		n--;
	}
	return 0;
}
