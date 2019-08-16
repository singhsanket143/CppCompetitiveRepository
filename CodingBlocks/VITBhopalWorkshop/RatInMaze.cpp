#include <iostream>
using namespace std;
int arr[7][7];
bool visited[7][7];
int result = 0;
bool isSafe(int n, int i, int j) {
	return i>=0 and j>=0 and i<n and j<n and arr[i][j]==0 and visited[i][j] == false;
}

void ratmaze(int n, int i, int j) {
	if(i==n-1 and j==n-1) {
		result++;
		return;
	}
	visited[i][j] = true;
	// work
	if(isSafe(n, i-1, j) == true) {
		ratmaze(n, i-1, j);
	}
	if(isSafe(n, i+1, j) == true) {
		ratmaze(n, i+1, j);
	}
	if(isSafe(n, i, j-1) == true) {
		ratmaze(n, i, j-1);
	}
	if(isSafe(n, i, j+1) == true) {
		ratmaze(n, i, j+1);
	}
	visited[i][j] = false;
}

int main(int argc, char const *argv[])
{
	int n=7;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>arr[i][j];
			visited[i][j] = false;
		}
	}
	ratmaze(n, 0, 0);
	cout<<result;
	return 0;
}
