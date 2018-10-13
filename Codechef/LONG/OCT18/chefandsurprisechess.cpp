#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;
	int mL = min(m,n);
	int *mM = new int(mL+1);
	int **arr = new int*[n];
	for(int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	for(int i = 0; i < n; i++) {
		string str;
		cin>>str;
		for(int j = 0; j < m; j++) {
			arr[i][j] = str[j]-'0';
		}
	}
	int **solution = new int*[n];
	for(int i = 0; i < n; i++) {
		solution[i] = new int[m];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			solution[i][j]=0;
		}
	}
	solution[0][0] = arr[0][0];
	int count = 0;
	for(int i = 1; i < m; i++) {
		if(i%2 != 0 and arr[0][i] != 1) {
			solution[0][i] = solution[0][i-1]+1;
		} else if(i%2 == 0 and arr[0][i] != 0) {
			solution[0][i] = solution[0][i-1]+1;
		} else {
			solution[0][i] = solution[0][i-1];
		}
	}
	for(int i = 1; i < n; i++) {
		if(i%2 != 0 and arr[i][0] != 1) {
			solution[i][0] = solution[i-1][0]+1;
		} else if(i%2 == 0 and arr[i][0] != 0) {
			solution[i][0] = solution[i-1][0]+1;
		} else {
			solution[i][0] = solution[i-1][0];
		}
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			int cand = ((i+j)%2==arr[i][j])?0:1;
			solution[i][j] = solution[i-1][j]+solution[i][j-1]-solution[i-1][j-1]+cand;
		}
	}

	for (int i = 0; i < maxLength; i++) {
		int a = solution[i][i];
		int b = (int)pow((i+1), 2);
		int c = b-a;
		mM[i+1] = Math.min(a, c);
    }
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout<<solution[i][j]<<" ";
		}
		cout<<endl;
	}
	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}
