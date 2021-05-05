#include <iostream>
#include<vector>
using namespace std;


void hello() {
	cout<<"Hello world"<<endl;
}


int fun(int n) {
	cout<<"fun with "<<n<<endl;
	return n;
}

void Print(int v) {
	cout<<"Value is "<<v<<endl;
}

void for_each(vector<int> &v, void(*func)(int)) {
	for(int value: v) {
		func(value);
	}
}

int main()
{
	/* code */
	int x = 10;
	int *p = &x;
	auto ptr = &hello;
	// void(*ptsr)() = hello;
	ptr();
	// cout<<ptr<<endl;
	// cout<<*ptr<<endl;


	// int(*fptr)(int) = fun;
	// fptr(7);



	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(14);

	for_each(v, Print);

	return 0;
}