#include <iostream>
using namespace std;
const int row=10;
const int col=3;
void display(int arr[row][col]) {
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			arr[i][j]=10;
		}
	}
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main(int argc, char const *argv[])
{
	int arr[10][3];
	display(arr);
	return 0;
}
