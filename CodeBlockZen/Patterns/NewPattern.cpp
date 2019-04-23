#include <iostream>
using namespace std;

void print(int n) {
	int val = -1;
	if(n%2==0) {
		val = n/2;
	} else {
		val = (n/2) + 1;
	}
	int counter = 1;
	for(int i=0;i<val;i++) {
		int temp = n*counter - n + 1;
		while(temp<=n*counter) {
			cout<<temp++<<" ";
		}
		counter+=2;
		cout<<"\n";
	}
	counter-=2;
	if(n%2==0) {
		counter++;
	} else {
		counter--;
	}
	// cout<<counter<<endl;
	for(int i=0;i<n-val;i++) {
		int temp = n*counter - n + 1;
		while(temp<=n*counter) {
			cout<<temp++<<" ";
		}
		counter-=2;
		cout<<"\n";
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	print(5);
	return 0;
}
