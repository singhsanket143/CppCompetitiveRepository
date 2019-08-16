#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	double sum = 0;
	for(int i=0;i<n;i++) {
		cin>>x;
		sum+=x;
	}
	printf("%0.12f", sum/n);
	return 0;
}
