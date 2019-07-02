#include <iostream>
using namespace std;

void countMazePath(int endrow, int endcol, int curr_row, int curr_col, string osf) {
	// base case
	if(curr_row == endrow and curr_col == endcol) {
		cout<<osf<<endl;
		return ;
	} 
	if(curr_row>endrow or curr_col>endcol) {
		return ;
	}

	countMazePath(endrow, endcol, curr_row+1, curr_col, osf+"V");
	countMazePath(endrow, endcol, curr_row, curr_col+1, osf+"H");
}

int main(int argc, char const *argv[])
{
	/* code */
	countMazePath(2, 2, 0, 0, "");
	return 0;
}
