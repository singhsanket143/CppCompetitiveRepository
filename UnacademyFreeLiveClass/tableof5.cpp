#include<iostream>
using namespace std;

int main() {

	cout<<"Please enter a number\n";
	int x;
	cin>>x;

	int i = 1;
	while(i <= x) {
		cout<<"5 x "<<i<<" = "<<(5*i)<<"\n";
		i += 1;
	}
	cout<<"Thanks!!";
	return 0;
}