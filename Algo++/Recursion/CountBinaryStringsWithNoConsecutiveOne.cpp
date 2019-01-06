#include <iostream>
using namespace std;

int countStrings(int n)
{
	int a[n], b[n];
	a[0] = b[0] = 1;
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i-1] + b[i-1];
		b[i] = a[i-1];
	}
	return a[n-1] + b[n-1];
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		cout << countStrings(n) << endl;
	}
	return 0;
}
