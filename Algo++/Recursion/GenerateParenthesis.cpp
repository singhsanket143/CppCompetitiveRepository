#include <iostream>
using namespace std;

void generateParenthesis(int n, int openB, int closeB, string str) {
	if(closeB == n) {
		cout<<str<<endl;
		return;
	}
	if(openB > closeB) {
		generateParenthesis(n, openB, closeB+1, str+')');
	}
	if(openB < n) {
		generateParenthesis(n, openB+1, closeB, str+'(');
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	generateParenthesis(3, 0, 0, "");
	return 0;
}
