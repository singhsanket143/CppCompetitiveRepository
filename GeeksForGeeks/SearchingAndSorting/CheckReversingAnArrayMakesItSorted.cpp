#include <iostream>
using namespace std;

bool check(int *arr, int n) {
	if(n==1)
		return true;
	int i;
	for(i=1;i<n and arr[i]>arr[i-1];i++) {}
	if(i==n) 
		return true;
	int j=i;
	while(arr[j]<arr[j-1]) {
		if(i>1 and arr[j]<arr[i-2])
			return false;
		j++;
	}
	if(j==n) 
		return true;
	int k=j;
	if(arr[k] < arr[i-1])
		return false;
	while(k<n and k>1) {
		if(arr[k]<arr[k-1]){
			return false;
		}
		k++;
	}
	return true;

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	check(arr, n)==true?cout<<"Yes":cout<<"No";
	return 0;
}
