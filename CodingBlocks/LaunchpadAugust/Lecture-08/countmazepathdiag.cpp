#include <iostream>
using namespace std;

int countMazePathdiag(int endrow, int endcol, int curr_row, int curr_col) {
	if(curr_row == endrow and curr_col == endcol) {
		return 1;
	}
	if(curr_row > endrow or curr_col > endcol) {
		return 0;
	}
	int hresult = countMazePathdiag(endrow, endcol, curr_row, curr_col+1);
	int vresult = countMazePathdiag(endrow, endcol, curr_row+1, curr_col);
	int dresult = countMazePathdiag(endrow, endcol, curr_row+1, curr_col+1);
	int myresult = hresult + vresult + dresult;
	return myresult;
}

int main(int argc, char const *argv[])
{
	cout<<countMazePathdiag(2,2,0,0);
	return 0;
}
