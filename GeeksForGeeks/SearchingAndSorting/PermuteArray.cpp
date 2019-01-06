#include <iostream>
#include <algorithm>
using namespace std;
void Permute(int *a, int *b, int n, int k) {
	sort(a, a+n);
	sort(b, b+n, greater<int>());
	for(int i=0;i<n;i++) {
		if(a[i]+b[i]<k) {
			cout<<"No";
			return;
		}
	}
	cout<<"Yes";
	return;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *a = new int[n];
	int *b = new int[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++) {
		cin>>b[i];
	}
	int k;
	cin>>k;
	Permute(a, b, n, k);
	return 0;
}
