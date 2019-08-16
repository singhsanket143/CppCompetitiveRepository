#include <iostream>
#include <algorithm>
using namespace std;
int factor(int A, int B) {
    while(__gcd(A, B)!=1) {
        A=A/__gcd(A,B);
    }
    return A;
}

int main(int argc, char const *argv[])
{
	/* code */
	int a, b;
	cin>>a>>b;
	cout<<factor(a,b);
	return 0;
}
