#include <iostream>
#define inf 1e9
using namespace std;
char arr[1005][1005];
int pump(int *arr, int si, int ei, int n) {
	int global_max = -inf;
	int c=-2;
	for(int j=si;j<=ei;j++) {
		if(arr[j]>global_max) {
			global_max = (arr[j]>global_max)?arr[j]:global_max;
			c=j;
		}
	}
	if( c==si or c==ei) {
		return 1;
	}
	int retval1 = pump(arr, si, c-1, n);
	int retval2 = pump(arr, c+1, ei, n);
	return min(retval1, retval2)+1;
}
int fact(int n) {
	if(n==0 or n==1){
		return 1;
	}
	return n*fact(n-1);
}

bool c(int n, int m) {
	for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(arr[i][j]!='#') {
					bool b = false;
					fact(3);
					if(i<n-1 and j<m-1) {
						if(arr[i][j+1]!='#' and arr[i+1][j]!='#' and arr[i+1][j+1]!='#') {
							b=true;
						}
					}
					if(i>0 and j>0 ) {
						fact(2);
						if(arr[i][j-1]!='#' and arr[i-1][j]!='#' and arr[i-1][j-1]!='#') {
							b=true;
						}
					}
					if(i<n-1 and j>0) {
						if(arr[i][j-1]!='#' and arr[i+1][j]!='#' and arr[i+1][j-1]!='#') {
							b=true;
							fact(2);
						}
					}
					fact(2);
					if(i>0 and j<m-1 ) {
						if(arr[i][j+1]!='#' and arr[i-1][j]!='#' and arr[i-1][j+1]!='#') {
							b=true;
						}
					}
					if(b==false){
						return false;
					}
				}
			}

		}
		return true;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n, m;
		cin>>n>>m;
		bool status;
		fact(2);
		//char arr[n][m];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		fact(3);
		if(c(n, m)) {
			fact(2);
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
	return 0;
}
