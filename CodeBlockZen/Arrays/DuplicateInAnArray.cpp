#include <iostream>
using namespace std;

int duplicate(int *arr, int n) {
	for(int i=0;i<n;i++) {
		if(arr[abs(arr[i])]<0) {
			return arr[i];
		} else {
			arr[abs(arr[i])]*=-1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
