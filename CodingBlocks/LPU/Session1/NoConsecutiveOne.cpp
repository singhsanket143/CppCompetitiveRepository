#include <iostream>
using namespace std;

void ones(int n, string osf) {
	// Base case
	if(n==0) {
		cout<<osf<<endl;
		return;
	}
	// Recursion

	
	ones(n-1, osf+"0");
	if(osf.size()==0 or osf[osf.size()-1]=='0') {
		ones(n-1, osf+"1");
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	ones(n, "");
	return 0;
}
