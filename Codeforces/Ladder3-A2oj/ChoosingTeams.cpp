#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, k, x;
	cin>>n>>k;
	int count = 0;
	for(int i=0;i<n;i++) {
		cin>>x;
		if(5-x>=k) {
			count++;
		}
	}
	cout<<count/3;
	return 0;
}
