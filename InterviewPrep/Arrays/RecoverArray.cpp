#include <iostream>
using namespace std;

void recoverArray(int *input, int *output, int n) {
	int mid = n/2;
	int i, left, right;
	if(n%2!=0) {
		output[mid] = input[0];
		left = mid-1;
		right = mid+1;
		i=1;
	} else {
		left = mid-1;
		right = mid;
		i=0;
	}
	while(i<n){
		output[left]= input[i];
		i++;
		output[right] = input[i];
		left--;
		right++;
		i++;
	}

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *input = new int[n];
	for(int i=0;i<n;i++) {
		cin>>input[i];
	}
	int *output = new int[n]();
	recoverArray(input, output, n);
	for(int i=0;i<n;i++) {
		cout<<output[i]<<" ";
	}
	return 0;
}
