#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		long long int n;
		cin>>n;
		long long int m3 = 0, m5 = 0, m15 = 0, temp = n, sum3 = 0, sum5 = 0, sum15 = 0;
		if(n%5 == 0) {
			temp = n-1;
		}
		m5 = temp/5;
		sum5 = ((long long int)(m5)*(10 + ((long long int)(m5-1)*5)))/2;
		temp = n;
		if(n%3 == 0) {
			temp = n-1;
		}
		m3 = temp/3;
		sum3 = ((long long int)(m3)*(6 + ((long long int)(m3-1)*3)))/2;
		temp = n;
		if(n%15 == 0) {
			temp = n-1;
		}
		m15 = temp/15;
		sum15 = ((long long int)(m15)*(30 + ((long long int)(m15-1)*15)))/2;
		cout<<sum3+sum5-sum15<<endl;
	}
	return 0;
}
