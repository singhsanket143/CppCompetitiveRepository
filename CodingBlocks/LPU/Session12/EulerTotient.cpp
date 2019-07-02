#include <iostream>
using namespace std;

int* totient(int n) {
	int *arr = new int[n+1];
	for(int i=0;i<=n;i++) {
		arr[i] = i;
	}
	for(int i=2;i<=n;i++) {
		if(arr[i] == i) {
			for(int j=i*2;j<=n;j+=i) {
				arr[j] = (arr[j] * (i-1))/(i);
			}
			arr[i]--;
		}
	}
	return arr;
}

int main(int argc, char const *argv[])
{
	/* code */
	int *arr;
	arr = totient(100);
	for(int i=0;i<100;i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}
