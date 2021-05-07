#include<bits/stdc++.h>
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

class ComplexNumber {
public:
	int real, img;
	int *ptr;

	// ComplexNumber() {
	// 	this->real = 0;
	// 	this->img = 0;
	// } //default -> random value init

	// constructor overloading
	ComplexNumber() : real(0), img(0) {}

	ComplexNumber(int real, int img) { // parameterized constructor
		this->real = real;
		this->img = img;
	}

	ComplexNumber(int real) {
		this->real = real;
	}

	int getReal() {
		return this->real;
	}

	int getReal(int x) {
		return this->real;
	}

	void display(int x) {
		cout<<x<<endl;
	}

	void display(float x) {
		cout<<x<<endl;
	}

	int show_real();

	// void getReal() { // function that differ only in return types are not overloaded
	// 	cout<<this->real<<endl;
	// }

	// ComplexNumber(int real = -1, int img = -1) {
	// 	this->real = real;
	// 	this->img = img;
	// }

	ComplexNumber(ComplexNumber& s) { // custom copy constructor to perform deep copy
		this->real = s.real;
		this->img = s.img;
		this->ptr = new int;
		*ptr = *(s.ptr);
	}

};

int ComplexNumber::show_real() { // :: scope resolution operator
	 real = 10;
	 return real;
}


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ComplexNumber c;
	cout<<c.real<<" "<<c.img<<endl;
	c.display('z'); // we dont have a function with char argument so it will try to do standard conversions

	int x = 10;
	c.ptr = &x;

	// ComplexNumber m;
	ComplexNumber m = c; // here copy constructor is called which initialises an object using other object of the class
	cout<<m.real<<" "<<m.img<<endl;
	m.real = 10;
	cout<<m.real<<" "<<m.img<<endl;
	cout<<c.real<<" "<<c.img<<endl;
	cout<<c.ptr<<" "<<m.ptr<<endl;
	cout<<*c.ptr<<" "<<*m.ptr<<endl;



	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
