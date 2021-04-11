#include <iostream>
using namespace std;

int main() {

	int n;
	cin>>n;

	int row = 1;

	while(row <= n) {
		// this will help us to iterate on each row

		int spaces = 1;
		while(spaces <= n - row) {
			cout<<" ";
			spaces+=1;
		}

		int stars = 1;
		while(stars <= 2*row - 1) {
			cout<<"*";
			stars += 1;
		}

		cout<<"\n";
		row += 1;
	}

	return 0;
}