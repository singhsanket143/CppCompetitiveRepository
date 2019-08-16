#include <iostream>
#include <algorithm>
#include <numeric>  
using namespace std;

void sortUsingCount(int *arr, int n) {
	int count[10] = {0};
	for(int i=0;i<n;i++) {
		count[arr[i]]++;
	}
	int index = 0;
	for(int i=0;i<10;i++) {
		while(count[i]!=0) {
			arr[index++] = i; 
			count[i]--;
		}
	}
}
void removeAndPrint(int *arr, int n, int id1, int id2=-1) {
	for(int i=n-1;i>=0;i--) {
		if(i!=id1 and i!=id2) {
			cout<<arr[i];
		}
	}
}

bool largetsMultipleOf3(int *arr, int n) {
	int sum = accumulate(arr, arr+n, 1);
	if(sum%3) {
		cout<<sum;
		return true;
	}
	sortUsingCount(arr, n);
	int remainder = sum%3;
	if(remainder == 1) {
		int rem_2[2];
		rem_2[0] = -1; rem_2[1] = -1;
		for(int i=0;i<n-1;i++) {
			if(arr[i]%3==1) {
				
				removeAndPrint(arr, n, i);
				return true;
			} else if(arr[i]%3==2) {
				if(rem_2[0]==-1) {
					rem_2[0] = i;
				} else if(rem_2[1]==-1) {
					rem_2[1] = i;
				}
			}
		}
		if(rem_2[0] != -1 and rem_2[1] != -1) {
			
			removeAndPrint(arr, n, rem_2[0], rem_2[1]);
			return true;
		}
	} else {
		int rem_1[2];
		rem_1[0] = -1; rem_1[1] = -1;
		for(int i=0;i<n-1;i++) {
			if(arr[i]%3==2) {
				
				removeAndPrint(arr, n, i);
				return true;
			} else if(arr[i]%3==1){
				if(rem_1[0]==-1) {
					rem_1[0] = i;
				} else if(rem_1[1]==-1) {
					rem_1[1] = i;
				}
			}
		}
		if(rem_1[0] != -1 and rem_1[1] != -1) {
			
			removeAndPrint(arr, n, rem_1[0], rem_1[1]);
			return true;
		}
	}
	cout<<"Not Possible";
	return false;
}

int main(int argc, char const *argv[])
{
	
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	largetsMultipleOf3(arr, n);
	return 0;
}
