#include <iostream>
using namespace std;
int config = 0;
void print(bool **visited, int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(visited[i][j] == false) {
				cout<<".";
			} else {
				cout<<"K";
				}
		}
		cout<<"\n";
	}
}

bool isItSafe(int n, int row, int col, bool **visited) {
	if(row-2>=0 and col-1>=0 and visited[row-2][col-1] == true) {
		return false;
	}
	if(row-2>=0 and col+1<n and visited[row-2][col+1] == true) {
		return false;
	}
	if(row-1>=0 and col-2>=0 and visited[row-1][col-2] == true) {
		return false;
	}
	if(row-1>=0 and col+2<n and visited[row-1][col+2] == true) {
		return false;
	}

	return true;
}


void Nknights(int n, bool **visited, int sr, int sc, int placed) {
	if(placed == n) {
		config++;
		//print(visited, n);
		//cout<<"*********************\n";
		return;
	}

	for(int i = sr; i < n; i++) {
		for(int j = (i==sr)?sc:0; j < n; j++) {
			if(isItSafe(n, i, j, visited)) {
				visited[i][j] = true;
				Nknights(n, visited, i, j+1, placed+1);
				visited[i][j] = false;
			}
		}
	}
	return;
}


int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	bool **visited = new bool*[n];
	for(int i=0;i<n;i++) {
		visited[i] = new bool[n]();
	}
	Nknights(n, visited, 0, 0, 0);
	cout<<config<<endl;
	return 0;
}
