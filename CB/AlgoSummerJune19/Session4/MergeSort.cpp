#include <iostream>
using namespace std;
int* merge(int *arr1, int *arr2, int n,  int m) {
	int *result = new int[n+m];
	int i=0, j=0, k=0;
	while(i<n and j<m) {
		if(arr1[i] <= arr2[j]) {
			result[k] = arr1[i];
			i++;
			k++;
		} else {
			result[k] = arr2[j];
			j++;
			k++;
		}
	}
	while(i<n) {
		result[k] = arr1[i];
		i++;
		k++;
	}
	while(j<m) {
		result[k] = arr2[j];
		j++;
		k++;
	}
	return result;
}
int* mergeSortHelper(int *arr, int start, int end) {
	if(start == end) {
		int *base = new int[1];
		base[0] = arr[start];
		return base;
	}

	int mid = (start+end)/2;
	int* left = mergeSortHelper(arr, start, mid);
	int* right = mergeSortHelper(arr, mid+1, end);
	int* result = merge(left, right, mid-start+1, end-mid);

	return result;
}


void mergeSort(int *arr, int n) {
	int* result = mergeSortHelper(arr, 0, n-1);
	for(int i=0;i<n;i++) {
		arr[i] = result[i];
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	mergeSort(arr, n);
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}