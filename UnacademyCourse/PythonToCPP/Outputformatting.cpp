#include<iostream>
#include<iomanip>
#include<ios>
#include<stdio.h>
using namespace std;

int main()
{
	for(int i = 1; i <= 10; i++) {
		cout<<"12 x "<<i<<setw(4)<<"="<<setw(15)<<(12*i)<<endl;
	}

	printf("hello %15d world", 5);
	return 0;
}