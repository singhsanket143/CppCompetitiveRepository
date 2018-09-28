#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i=1;
	int val = 1;
	int state = 0;
	while(i<=n) {
		// Work done
		int j=1;
		state = 1-state;
		val = state;
		while(j<=i) {
			
			cout<<val<<" ";
			val = 1-val;
			
			j++;
		}
		cout<<"\n";

		i++;
	}
	return 0;
}
