#include <iostream>
using namespace std;

int mazePath(int cr, int cc, int er, int ec, string osf) {
	if(cr == er and cc == ec) {
		cout<<osf<<endl;
		return 1; // one valid way found
	}
	if(cr > er or cc > ec) {
		return 0;
	}
	int hval = mazePath(cr, cc+1, er, ec, osf+"H");
	int vval = mazePath(cr+1, cc, er, ec, osf+"V");
	return hval+vval;
}

int main(int argc, char const *argv[])
{
	/* code */
	cout<<mazePath(0, 0, 2,2, "");
	return 0;
}
