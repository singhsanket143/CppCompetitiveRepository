#include<iostream>
using namespace std;


int lt[30] = {0};
int rt[30] = {0};
int col[30] = {0};

void nqueen(int board[][10],int n,int i,int &ans){
	//Base Case
	if(i==n){
		//Print the board
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<board[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		ans++;
		return;
	}
	//Rec Case
	for(int j=0;j<n;j++){
		if(col[j]==0 and lt[i-j+n-1]==0 and rt[i+j]==0){
			col[j] = lt[i-j+n-1] = rt[i+j] = 1;
			//Assume Subproblem has been solved
			board[i][j] = 1;
			nqueen(board,n,i+1,ans);
			// Backtracking
			board[i][j] = 0;
			col[j] = lt[i-j+n-1] = rt[i+j] = 0;
		}
	}
}



int main(){
	int n;
	cin>>n;
	int ans = 0;
	int board[10][10] = {0};


	nqueen(board,n,0,ans);
	cout<<ans<<endl;
	return 0;

}