#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

class Test {
public:
	int count;
	int arr[100];

	Test() : count(0) {}

	Test(int c) : count(c) {}

	int get_count() const {
		return this->count;
	}

	int set_count(int x) {
		this->count = x;
	}

	// overload unary operator ++(prefix, postfix), --()

	// case 1 : overload prefix ++

	Test operator ++() {
		++this->count;
		return Test(this->count);
	}

	// case 2 : overload postfix ++

	Test operator ++(int) {
		return Test(this->count++);
	}

	// case 3 : overload Binary Operator (+, -, * ...)

	Test operator +(Test v) {
		cout<<this->count<<endl;
		int temp = this->count + v.count;
		return Test(temp);
	}

	// case 4 : overload comparison operator

	bool operator < (Test v) {
		bool b = this->count < v.count;
		return b;
	}

	// case 5 : overload assignment operator

	void operator += (Test& v) {
		this->count += v.count;
	}

	// case 6 : overload subscript operator ([])

	int& operator [](int n) {
		if(n < 0 or n >= 100) exit(1);
		// this->arr[n] = 10;
		return this->arr[n];
	}


	// operator that cant be overloaded
	/*
		1. (.) dot operator
		2. (?:) ternary operator
		3. (::) scope resolution operator
		4. (.*) pointer to member
		5. (sizeof) size of operator
		6. (typeid) 
	*/
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	Test t;
	cout<<t.get_count()<<endl;
	Test x = ++t;
	cout<<t.get_count()<<endl;
	cout<<x.get_count()<<endl;

	x.set_count(3);
	Test c = x + t; // x asks to add t, t is passed as argument to the overloaded + operator
	cout<<c.get_count()<<endl;

	bool b = c < t;
	// cout<<b<<endl;


	c += t;
	cout<<c.get_count()<<" "<<t.get_count()<<endl;


	c[2] = 10;
	// cout<<c[1]<<" "<<c[2]<<endl;

	int i, j;
	char ch;
	const type_info& typei = typeid(i);
	const type_info& typej = typeid(j);
	const type_info& typech = typeid(ch);
	cout<<(typei == typej)<<endl;
	cout<<(typei == typech)<<endl;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
