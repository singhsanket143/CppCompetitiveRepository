#include <iostream>
using namespace std;

void sleep() {
	for(int i=0;i<100000000;i++) {
		//
	}
}

void print(char **arr, int r, int c) {
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			cout<<arr[i][j];
		}
		cout<<"\n";
	}
}

void floodFill(char **arr, int i, int j, char ch, int r, int c) {
	if(i<0 or i>=r or j<0 or j>=c or arr[i][j]=='#') {
		return;
	}
	if(arr[i][j]==ch) return;
	arr[i][j] = ch;
	sleep();
	system("clear");
	print(arr, r, c);

	floodFill(arr, i+1, j, ch, r, c);
	floodFill(arr, i-1, j, ch, r, c);
	floodFill(arr, i, j+1, ch, r, c);
	floodFill(arr, i, j-1, ch, r, c);


}

int main(int argc, char const *argv[])
{
	int r, c;
	cin>>r>>c;
	char **arr = new char*[r];
	for(int i=0;i<r;i++) {
		arr[i] = new char[c];
	}
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			cin>>arr[i][j];
		}
	}
	print(arr, r, c);
	floodFill(arr, 10, 13, 'R', r, c);
	print(arr, r, c);
	return 0;
}
