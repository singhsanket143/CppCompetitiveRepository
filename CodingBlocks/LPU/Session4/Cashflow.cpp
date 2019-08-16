#include <iostream>
using namespace std;

int getMin(int *arr, int n) {
	int minidx = 0;
	for(int i=1;i<n;i++) {
		if(arr[i]<arr[minidx]) {
			minidx = i;
		}
	}
	return minidx;
}

int getMax(int *arr, int n) {
	int maxidx = 0;
	for(int i=1;i<n;i++) {
		if(arr[i]>arr[maxidx]) {
			maxidx = i;
		}
	}
	return maxidx;
}

void cashflow(int *transaction, int n) {
	int minidx = getMin(transaction, n);
	int maxidx = getMax(transaction, n);

	if(transaction[minidx]==0 and transaction[maxidx] == 0) {
		return;
	}
	int cash = max(transaction[minidx], transaction[maxidx]);
	cout<<"Person "<<maxidx<<" will pay "<<cash<<" to "<<minidx<<endl;;;;;;;;;;
	transaction[maxidx]-=cash;
	transaction[minidx]+=cash;
	cashflow(transaction, n);

}




int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int **arr = new int*[n];
	for(int i=0;i<n;i++) {
		arr[i] = new int[n];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>arr[i][j];
		}
	}
	int *transaction = new int[n];

	for(int i=0;i<n;i++) transaction[i]=0;

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i==j) continue;
			transaction[i]+=(arr[i][j]-arr[j][i]);
		}
	}
	cashflow(transaction, n);
	return 0;
}