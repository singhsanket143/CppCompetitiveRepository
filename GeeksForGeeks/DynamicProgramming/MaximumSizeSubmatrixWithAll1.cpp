#include <iostream>
using namespace std;

void binarySubMatrix(int **arr, int n, int m) {
	int **subMatrix = new int*[n];
	for(int i=0;i<n;i++) {
		subMatrix[i] = new int[m];
	}

	for(int i=0;i<n;i++) {
		subMatrix[i][0] = arr[i][0];
	}

	for(int i=0;i<m;i++) {
		subMatrix[0][i] = arr[0][i];
	}

	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) {
			if(arr[i][j]==1)
				subMatrix[i][j] = min(subMatrix[i][j-1], min(subMatrix[i-1][j-1], subMatrix[i-1][j])) + 1;
			else
				subMatrix[i][j] = 0;
		}
	}

	// for(int i=0;i<n;i++) {
	// 	for(int j=0;j<m;j++) {
	// 		cout<<subMatrix[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	int x_coordinate = 0, y_coordinate = 0, max_value = INT_MIN;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(max_value < subMatrix[i][j]) {
				x_coordinate = i;
				y_coordinate = j;
				max_value = subMatrix[i][j];
			}
		}
	}
	// cout<<x_coordinate<<" "<<y_coordinate<<" "<<max_value;
	cout<<max_value;
}


int main(int argc, char const *argv[])
{
	// int arr[6][5] = {{0,1,1,0,1}, {1,1,0,1,0}, {0,1,1,1,0}, {1,1,1,1,0}, {1,1,1,1,1}, {0,0,0,0,0}};
	int n, m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i=0;i<n;i++) {
		arr[i] = new int[m];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>arr[i][j];
		}
	}
	binarySubMatrix(arr, n, m);
	return 0;
}
