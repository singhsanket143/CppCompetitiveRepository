#include <iostream>
using namespace std;

void performCrane(int *arr, int n, long h) {
	int crane=0, inst;
    cin>>inst;
	bool status = false;
	while(inst != 0) {
		if(inst == 1) {
			if(crane>0) {
				crane--;
			}
		} else if(inst == 2) {
			if(crane<n-1) {
				crane++;
			}
		} else if(inst == 3) {
			if(status == false and arr[crane] > 0){
				arr[crane]--;
				status = true;
			}
		} else if(inst == 4) {
			if(status == true and arr[crane] < h){  
				arr[crane]++;
				status = false;
			}
		} 
        cin>>inst;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	long h;
	cin>>n>>h;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	performCrane(arr, n, h);
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}
