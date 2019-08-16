#include <iostream>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
	int q;
	cin>>q;
	while(q--) {
		int n, m;
		cin>>n>>m;
		string *arr = new string[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		char arr1[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				arr1[i][j] = arr[i][j];
			}
		}

		ll money = 0;
		int best_row = -1;
		int best_sum = INT_MIN;
		for(int i=0;i<n;i++) {
			int sum = 0;	
			for(int j=0;j<m;j++) {
				if(arr[i][j]=='*') {
					sum++;
				}
			}
			if(sum>best_sum) {
				best_sum = sum;
				best_row = i;
			}
		}
		for(int j=0;j<m;j++) {
			if(arr[best_row][j] == '.') {
				arr[best_row][j] = '*';
				money++;
			}
		}

		int best_col = -1;
		int best_sum1 = INT_MIN;
		for(int i=0;i<m;i++) {
			int sum = 0;	
			for(int j=0;j<n;j++) {
				if(arr[j][i]=='*') {
					sum++;
				}
			}
			if(sum>best_sum1) {
				best_sum1 = sum;
				best_col = i;
			}
		}
		for(int j=0;j<n;j++) {
			if(arr[j][best_col] == '.') {
				arr[j][best_col] = '*';
				money++;
			}
		}
		//////////


		ll money1 = 0;
		int best_col1 = -1;
		int best_sum12 = INT_MIN;
		for(int i=0;i<m;i++) {
			int sum = 0;	
			for(int j=0;j<n;j++) {
				if(arr1[j][i]=='*') {
					sum++;
				}
			}
			if(sum>best_sum12) {
				best_sum12 = sum;
				best_col1 = i;
			}
		}
		for(int j=0;j<n;j++) {
			if(arr1[j][best_col1] == '.') {
				arr1[j][best_col1] = '*';
				money1++;
			}
		}

		int best_row1 = -1;
		int best_sum11 = INT_MIN;
		for(int i=0;i<n;i++) {
			int sum = 0;	
			for(int j=0;j<m;j++) {
				if(arr1[i][j]=='*') {
					sum++;
				}
			}
			if(sum>best_sum11) {
				best_sum11 = sum;
				best_row1 = i;
			}
		}
		for(int j=0;j<m;j++) {
			if(arr1[best_row1][j] == '.') {
				arr1[best_row1][j] = '*';
				money1++;
			}
		}
		
		if(money<money1) {
			cout<<money<<endl;
		} else {
			cout<<money1<<endl;
		}
		delete [] arr;
	}
	return 0;
}
