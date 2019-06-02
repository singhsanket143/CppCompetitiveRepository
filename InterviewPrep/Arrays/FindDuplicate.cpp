#include <iostream>
using namespace std;

int duplicate(int *arr, int n) {
	for(int i=0;i<n;i++) {
		if(arr[abs(arr[i])]<0) {
			return abs(arr[i]);
		}
		arr[abs(arr[i])]*=-1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	
	
	cout<<duplicate(arr, n);
	return 0;
}
