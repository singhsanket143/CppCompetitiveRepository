#include<iostream>
using namespace std;
int main() {
	// arithmetic
	int a, b;
	cin>>a>>b;
	cout<<a + b;
	cout<<a - b;
	cout<<a * b;
	cout<<a / b;
	cout<<a%b;

	int m = 8 * (i++); // i will be used first and then incremented
	i--; // i will be used first and then decremeneted
	++i; // i will be incremented first and then used
	--i; // i will be decremented first and then used;


	// boolean
	bool c, d;
	cout<<c and d;
	cout<<c or d;
	cout<<not c;
	cout<<c && d;
	cout<<c || d;
	cout<<!c;

	// bitwise
	cout<<c & d; // and
	cout<<c | d; // or
	cout<<~c; // compliment
	cout<<c ^ d; // xor
	cout<<(c<<2); // left shift
	cout<<(d>>3); // right shift

	// assignment operator
	int i;
	i = 10;
	i = i + 1;
	i = i - 1;
	i += i;
	i -= 1;
	i = i * 1;
	i *= 1;
	i = i / 1;
	i /= 1;

	// comparison
	int x, y;
	cout<<x < y;
	cout<<x > y;
	cout<<x <= y;
	cout<<x >= y;
	cout<<x == y;
	cout<<x != y;


	// ternary operator
	int z = (10 > 45) ? 100 : 67;
	return 0;
}