#include <iostream>
using namespace std;

bool arr[100][100];
int result = 0;

bool isSafe(int x, int y, int n) {
	for(int i = x-1; i>=0; i--) {
		if(arr[i][y] == true) {
			return false;
		}
	}

	for(int i=x-1, j=y-1;i>=0 and j>=0;i--, j--) {
		if(arr[i][j] == true) {
			return false;
		}
	}

	for(int i=x-1, j=y+1;i>=0 and j<n;i--, j++) {
		if(arr[i][j] == true) {
			return false;
		}
	}
	return true;
}

void nqueen(int n, int curr_row) {
	if(curr_row >= n) {
		result++;
		return;
	}
	for(int i=0;i<n;i++) {
		if(isSafe(curr_row, i, n)) {
			arr[curr_row][i] = true;
			nqueen(n, curr_row+1);
			arr[curr_row][i] = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	nqueen(n, 0);
	cout<<result;
	return 0;
}
