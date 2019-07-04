#include <iostream>
using namespace std;

void lexico(int n, int x) {
	if(x>n) {
		return;
	}
	if(x==n) {
		cout<<x<<endl;
		return;
	}
	if(x!=0) {
		cout<<x<<endl;
	}
	for(int i = (x == 0)?1:0;i<=9;i++) {
		lexico(n, 10*x+i);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	lexico(1000, 0);
	return 0;
}
