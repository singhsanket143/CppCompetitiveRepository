#include<iostream>
using namespace std;


long long int fact(int n) {
	long long int ans = 1;
	for(int i = 2; i <= n; i++) {
		ans *= i;
	}
	return ans;
}

int main()
{
	cout<<fact(5);
	return 0;
}