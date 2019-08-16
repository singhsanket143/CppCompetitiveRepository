#include <iostream>
using namespace std;

void findZeros(int *arr, int n, int k) {
	int wL = 0, wR = 0, bestWindow = 0, zeroCount = 0, bestL = 0;
	while(wR < n) {
		if(zeroCount<=k) {
			if(arr[wR] == 0) 
				zeroCount++;
			wR++;
		} 
		if(zeroCount>k) {
			if(arr[wL] == 0) 
				zeroCount--;
			wL++;
		}
		if((wR-wL) > bestWindow and (zeroCount<=k)) {
			bestWindow = wR-wL;
			bestL = wL;
		}
	}
	// cout<<bestWindow<<","<<wR<<","<<wL<<","<<bestL<<endl;
    cout<<bestWindow<<endl;
	for(int i=0;i<bestL;i++) {
		cout<<arr[i]<<" ";
	}
	for(int i=bestL;i<bestL+bestWindow;i++) {
		if(arr[i]==0)
			arr[i]=1;
		cout<<arr[i]<<" ";
	}
	for(int i=bestL+bestWindow;i<n;i++) {
		cout<<arr[i]<<" ";
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int n, k;
	cin>>n>>k;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	
	findZeros(arr, n, k);
	return 0;
}
