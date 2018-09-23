#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int row, col;
	cin>>row>>col;
	int arr[row][col];
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			cin>>arr[i][j];
		}
	}
	for(int col_iterate=0;col_iterate<col;col_iterate++) {
		if(col_iterate%2==0) {
			for(int row_iterate=0;row_iterate<row;row_iterate++) {
				cout<<arr[row_iterate][col_iterate]<<", ";
			}
		} else {
			for(int row_iterate=row-1;row_iterate>=0;row_iterate--) {
				cout<<arr[row_iterate][col_iterate]<<", ";
			}
		}
	}
	return 0;
}
