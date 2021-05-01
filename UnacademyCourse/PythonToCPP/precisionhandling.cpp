#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main()
{
	// float pi = 3.141592;
	// cout<<fixed<<setprecision(4)<<pi<<endl;

	// float x = 3.17765;
	// cout<<fixed<<setprecision(13)<<x<<endl; // fixed is called fixed notation
	// x = 4453.0;
	// cout<<scientific<<setprecision(3)<<x<<endl;


	cout.precision(5);
	float f = 4.32245698;
	cout<<f<<endl;
	cout<<fixed<<f<<endl;

	printf("%0.3f\n", f);

	long double d = 3.146237885;
	printf("%0.5Lf\n", d);
	cout<<fixed<<d<<endl;
	return 0;
}