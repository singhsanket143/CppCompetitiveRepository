#include <iostream>
using namespace std;

int countMazePath(int endrow, int endcol, int curr_row, int curr_col) {
	// base case
	if(curr_row == endrow and curr_col == endcol) {
		return 1;
	} 
	if(curr_row>endrow or curr_col>endcol) {
		return 0;
	}

	int r_result = countMazePath(endrow, endcol, curr_row+1, curr_col);
	int h_result = countMazePath(endrow, endcol, curr_row, curr_col+1);
	int d_result = 0;
	if(curr_col == curr_row or curr_row+curr_col==endrow-1) {
		d_result = countMazePath(endrow, endcol, curr_row+1, curr_col+1);
	}
	return r_result+h_result+d_result;
}

int main(int argc, char const *argv[])
{
	/* code */
	cout<<countMazePath(2, 2, 0, 0);
	return 0;
}
