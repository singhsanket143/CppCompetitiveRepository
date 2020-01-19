#include <iostream>
using namespace std;

int search(int **arr, int n, int m, int key) { // O(n+m)
	if(n==0) return -1;
	int i = 0, j = n-1;
	while(i < n and j >= 0) {
		if(arr[i][j] == key) {
			cout<<i<<","<<j<<endl;
			return 1;
		} else if (arr[i][j] > key) {
			j-=1;
		} else {
			i+=1;
		}
	}
	cout<<"Element not found"<<endl;
	return 0;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin>>arr[i][j];
		}
	}
	int key;
	cin>>key;
	cout<<search(arr, n, m, key)<<endl;
	return 0;
}