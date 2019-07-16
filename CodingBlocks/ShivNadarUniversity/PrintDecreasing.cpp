#include <iostream>
using namespace std;

void pdec(int n) {
	if(n==0) {
		return;
	}
	cout<<n<<endl;
	pdec(n-1);
}

int main(int argc, char const *argv[])
{
	pdec(5);
	return 0;
}
