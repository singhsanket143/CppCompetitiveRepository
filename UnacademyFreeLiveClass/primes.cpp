#include<iostream>
using namespace std;

int main()
{
	cout<<"Please enter the number\n";
	int n;
	cin>>n;

	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			cout<<"Given number is not a prime";
			return 0;
		}
	}

	cout<<"Given number is a prime";
	return 0;
}