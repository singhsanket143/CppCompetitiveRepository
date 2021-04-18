#include<iostream>
#include<vector>
#define vvi vector<vector<int> >
using namespace std;

bool can_we_go(int i, int j, vvi &mat, vvi &vis) {
	int n = mat.size();
	return i >= 0 and j >= 0 and i < n and j < n and mat[i][j]==0 and vis[i][j] == 0;
}

int ans = 0;

void count_path(vvi &mat, vvi &vis, int i, int j) {
	int n = mat.size();
	if(i == n-1 and j == n-1) {
		ans+=1;
		return;
	}

	vis[i][j] = 1;
	// up
	if(can_we_go(i-1, j, mat, vis) == true)
		count_path(mat, vis, i-1, j);
	// left
	if(can_we_go(i, j-1, mat, vis) == true)
		count_path(mat, vis, i, j-1);
	// down
	if(can_we_go(i+1, j, mat, vis) == true)
		count_path(mat, vis, i+1, j);
	// right
	if(can_we_go(i, j+1, mat, vis) == true)
		count_path(mat, vis, i, j+1);
	vis[i][j] = 0;
}


int main()
{
	int n;
	cin>>n;
	vector<vector<int> > mat(n, vector<int>(n));
	vector<vector<int> > vis(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin>>mat[i][j];
		}
	}
	count_path(mat, vis, 0, 0);
	cout<<ans;
	return 0;
}