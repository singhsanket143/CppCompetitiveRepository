#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[][4] = {{1,2,3,4}, {11,14,15,16}, {21,24,27,28},{31,33,34,37}};
	int key = 27;

	// Approach 1 - Linear Search In Every Row
	for(int row=0;row<4;row++) {
		for(int col=0;col<4;col++) {
			if(arr[row][col] == key) {
				cout<<row<<","<<col;
				return 0;
			}
		}
	}

	// Approach 2 -  Binary Search In Every Row


	// Approach 3 - Optimised Approach
	for(int row = 0;row < 3;) {
		for(int col=3;col>=0;) {
			if(arr[row][col] == key) {
				cout<<row<<" "<<col;
				return 0;
			} else if(arr[row][col] > key) {
				col--;
			} else {
				row++;
			}
		}
	}
 	return 0;
}
