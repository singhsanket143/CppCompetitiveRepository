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


int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;
	int *arr1 = new int[n];
	int *arr2 = new int[m];
	for(int i=0;i<n;i++) {
		cin>>arr1[i];
	}
	for(int i=0;i<m;i++) {
		cin>>arr2[i];
	}
	int *sorted_array = merge(arr1, arr2, n, m);
	for(int i=0;i<n+m;i++) {
		cout<<sorted_array[i]<<" ";
	}
	return 0;
}
