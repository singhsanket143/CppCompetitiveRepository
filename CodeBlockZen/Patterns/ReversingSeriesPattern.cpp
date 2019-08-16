#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int counter = 0, value=1;
	for(int i=1;i<=n;i++) {
		if(i%2==0) {
			counter+=2;
		}
		value+=counter;
		for(int j=1;j<=i;j++) {
			cout<<value<<" ";
			if(i%2==0 and j!=i) value--;
			else if(i%2!=0 and j!=i) value++;
		}
		cout<<endl;

	}
	return 0;
}
