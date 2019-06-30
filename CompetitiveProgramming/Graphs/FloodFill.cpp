#include <iostream>
using namespace std;

int R, C;

void sleep() {
	for(int i=0;i<100000000;i++) {
		//
	}
}

void printMat(char mat[][50]) {
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++) {
			cout<<mat[i][j];
		}
		cout<<"\n";
	}
}

void floodFill(char mat[][50], int i, int j, char ch, char color) {
	if(i<0 or j<0 or i>=R or j>=C or mat[i][j]!=ch) {
		return;
	}
	system("clear");
	printMat(mat);
	sleep();
	mat[i][j] = color;
	floodFill(mat, i+1, j, ch, color);
	floodFill(mat, i-1, j, ch, color);
	floodFill(mat, i, j+1, ch, color);
	floodFill(mat, i, j-1, ch, color);
}

int main(int argc, char const *argv[])
{
	char mat[50][50];
	cin>>R>>C;
	for(int i=0;i<R;i++) {
		for(int j=0;j<C;j++) {
			cin>>mat[i][j];
		}
	}
	printMat(mat);
	floodFill(mat, 8, 13, '.', 'R');
	printMat(mat);
	return 0;
}
