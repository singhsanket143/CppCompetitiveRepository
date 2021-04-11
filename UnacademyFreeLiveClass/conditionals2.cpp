#include<iostream>
using namespace std;

int main() {

	cout<<"please enter the number you want to check\n";
	int x;
	cin>>x;
	if(x % 3 == 0 and x % 5 == 0) {
		cout<<"Divisible by both 3, 5\n";
	} else if(x % 3 == 0) {
		cout<<"Divisible by 3\n";
	} else if(x % 5 == 0) {
		cout<<"Divisible by 5\n";
	} else {
		cout<<"Not divisible by 3 or 5\n";
	}

	cout<<"Thank you";

	return 0;
}