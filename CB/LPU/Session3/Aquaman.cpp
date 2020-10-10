#include <iostream>
#include <math.h>
using namespace std;
int result = 0;
void trident(int a, int b, string osf, int sum, int k) {
	if(sum == a) {
		cout<<osf<<endl;
		result++;
		return;
	}
	if(sum > a) {
		return;
	}
	if(pow(k, b) > a) {
		return;
	}

	trident(a, b, osf+to_string(k)+" ", sum+pow(k, b), k+1);
	trident(a, b, osf, sum, k+1);
}

int main(int argc, char const *argv[])
{
	/* code */
	int a, b;
	cin>>a>>b;
	trident(a, b, "", 0, 1);
	cout<<result;
	return 0;
}
