#include <iostream>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		ll p1, p2, k;
		cin>>p1>>p2>>k;
		ll sum = p1+p2;
		ll quo = sum/k;
		ll rem = sum%k;
		if(quo%2==0) {
			cout<<"CHEF\n";
		} else {
			cout<<"COOK\n";
		}
	}
	return 0;
}
