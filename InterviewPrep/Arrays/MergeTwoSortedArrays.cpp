#include <iostream>
using namespace std;

void merge(int *arr1, int n, int *arr2, int m, int *ans) {
	int i = 0, j = 0, k = 0;
	while(i<n and j<m) {
		if(arr1[i]<arr2[j]) {
			ans[k++] = arr1[i++];
		} else {
			ans[k++] = arr2[j++];
		}
	}
	while(i<n) {
		ans[k++] = arr1[i++];
	}
	while(j<m) {
		ans[k++] = arr2[j++];
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n;
	int *arr1 = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr1[i];
	}
	cin>>m;
	int *arr2 = new int[m];
	for(int i=0;i<m;i++) {
		cin>>arr2[i];
	}

	int *ans = new int[n+m];
	merge(arr1, n, arr2, m, ans);
	for(int i=0;i<n+m;i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
