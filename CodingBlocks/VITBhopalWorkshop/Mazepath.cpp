#include <iostream>
using namespace std;

int maze(int n, int m, int cr, int cc) {
	if(cr == n-1 and cc == m-1) {
		return 1;
	}
	if(cr >= n or cc >=m) {
		return 0;
	}
	int rightans = maze(n, m, cr, cc+1);
	int downans = maze(n, m, cr+1, cc);
	return rightans + downans;
}

int main(int argc, char const *argv[])
{
	cout<<maze(3,4,0,0);
	return 0;
}
