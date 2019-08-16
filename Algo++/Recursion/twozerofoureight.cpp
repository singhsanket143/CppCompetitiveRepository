#include <iostream>
using namespace std;

string spell[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void print(int n) {
	if(n==0) {
		return;
	}
	print(n/10);
	cout<<spell[n%10]<<" ";
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	print(n);
	return 0;
}
