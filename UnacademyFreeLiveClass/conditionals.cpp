#include<iostream>
using namespace std;

int main() {

	// checks if a number is even or odd ???
	cout<<"Please enter a number you want to check\n";
	int x;
	cin>>x; // x =10
	if(x%2 == 0) {
		cout<<"This is an even number\n";
	} else {
		cout<<"This is an odd number\n";
	}

	cout<<"Thank you\n";

	return 0;
}