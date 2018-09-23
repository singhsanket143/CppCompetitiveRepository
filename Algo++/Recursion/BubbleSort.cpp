#include <iostream>
using namespace std;

void bubblesort(int arr[], int j, int n) {
	if(n==1) {
		return;
	}
	if(j==n-1) {
		return bubblesort(arr, 0, n-1);
	}
	if(arr[j]>arr[j+1]) {
		swap(arr[j], arr[j+1]);
	}
	return bubblesort(arr, j+1, n);
}

int main(int argc, char const *argv[])
{
	int arr[] = {5,4,3,2,1};
	bubblesort(arr, 0, 5);
	for(int i=0;i<5;i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}
