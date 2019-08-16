#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int temp = n;
	while(n > 0) {
		int num = temp-n;
		num = temp-num;
		for(int i=0;i<temp-n+1;i++) {
			cout<<num++;
		}
        for(int i=0;i<n-1;i++) {
			cout<<temp;
		}
		cout<<endl;
		n--;
	}
	return 0;
}
