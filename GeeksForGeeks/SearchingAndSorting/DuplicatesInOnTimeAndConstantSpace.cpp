#include <iostream>
using namespace std;

void checkDuplicate(int *arr, int n) {
	for(int i=0;i<n;i++) {
		if(arr[abs(arr[i])]>=0) {
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		} else {
			cout<<abs(arr[i])<<" ";
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {1, 2, 3, 1, 3, 6, 6}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    checkDuplicate(arr, arr_size); 
	return 0;
}
