#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	bool status=true;
	while(n > 0) {
		for(int i=0;i<n;i++) {
			if(status) {
				cout<<1;
			} else {
				cout<<0;
			}
		}
		cout<<endl;
		status = !status;
		n--;
	}
	return 0;
}
