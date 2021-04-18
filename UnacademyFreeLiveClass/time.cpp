#include<iostream>
using namespace std;

int main() {

	cout<<"start\n";
	long long int a = 0;
	for(int i = 0; i < 10000000000; i++) {
		a++;
	}
	cout<<a<<"\n";
	cout<<"end";

	return 0;
}