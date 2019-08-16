#include <iostream>
using namespace std;

void lexico(int end, int curr) {
	if(end == curr) {
		cout<<curr<<endl;
		return;
	}
	if(end < curr) {
		return;
	}
	
	for(int i = 9; i >= (curr==0)?1:0; i--) {
		lexico(end, 10*curr + i);
	}
	cout<<curr<<endl;
}
int main(int argc, char const *argv[])
{
	/* code */
	lexico(1000, 0);
	return 0;
}
