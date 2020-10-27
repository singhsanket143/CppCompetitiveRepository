#include<iostream>
using namespace std;
int main() {
	int testcases;
	cin>>testcases;

	for (int i = 0; i < testcases; i++) {
		long long int N;
		cin>>N;
		// First calculate sum of multiples of 3
		// sum = (x/2)*(2a + (x-1)d)
		long long int x = (N-1)/3;
		long long int sum_of_multiple_of_3 = ((x) * (2*3 + (x-1)*3))/2;

		//cout<<sum_of_multiple_of_3<<endl;
		//  calculate sum of multiples of 5
		long long int y = (N-1)/5;
		long long int sum_of_multiple_of_5 = ((y) * (2*5 + (y-1)*5))/2;
		//cout<<sum_of_multiple_of_5<<endl;

		// First calculate sum of multiples of 15
		long long int z = (N-1)/15;
		long long int sum_of_multiple_of_15 = ((z) * (2*15 + (z-1)*15))/2;

		//cout<<sum_of_multiple_of_15<<endl;
		cout<<(sum_of_multiple_of_3 + sum_of_multiple_of_5 - sum_of_multiple_of_15)<<endl;


	}
	
}