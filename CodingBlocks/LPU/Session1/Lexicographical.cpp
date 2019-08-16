#include <iostream>
using namespace std;

void lexico(int n, int limit) {
	if(n>limit) { // Base case
		return;
	}
	if(n == limit) {
		cout<<n<<endl;
		return;
	}

	// self work
	cout<<n<<endl;
	// Assumption

	for(int i = (n==0)?1:0; i<=9;i++) {
		lexico(10*n + i, limit);
	}
} 

int main(int argc, char const *argv[])
{
	/* code */
	int limit;
	cin>>limit;
	lexico(0, limit);
	return 0;
}
