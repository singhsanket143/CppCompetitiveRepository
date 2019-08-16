#include <iostream>
using namespace std;

int partition(int *arr, int start, int end) {
	int i = start-1;
	int j = start;
	int pivot = arr[end];
	while (j < end) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
		j++;
	}
	swap(arr[i+1], arr[end]);
	return i+1;
}

void quickSortHelper(int *arr, int start, int end) {
	if(start >= end) {
		return;
	}

	int pivot = partition(arr, start, end);
	quickSortHelper(arr, start, pivot - 1);
	quickSortHelper(arr, pivot+1, end);
}

void quickSort(int *arr, int n) {
	quickSortHelper(arr, 0, n - 1);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	quickSort(arr, n);
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}

	return 0;
}
