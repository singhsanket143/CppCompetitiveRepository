#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int counter=1, term = 1;
	while(counter <= n) {
		if((term*3+2) % 4 == 0) {
			term++;
			continue;
		}
		cout<<(term*3+2)<<" ";
		term++;
		counter++;
	}
	return 0;
}
