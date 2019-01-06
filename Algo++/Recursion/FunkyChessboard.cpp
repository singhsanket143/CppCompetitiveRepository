#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int n,cols,empty,board[10][10],sum=0,hi;

void set(int i,int j,int count){
    if(i<0 || i>=10 || j<0 || j>=10 || board[i][j] == 0)
        return;
    int ans = 0;
    board[i][j] = 0;//unsets the (i,j) cell
    hi = max(hi,count+1);//hi stores the maximum of value of visited squares
    //try all 8 possible moves for knight
    set(i-1,j-2,count+1);
    set(i-2,j-1,count+1);
    set(i+1,j-2,count+1);
    set(i+2,j-1,count+1);
    set(i-1,j+2,count+1);
    set(i-2,j+1,count+1);
    set(i+1,j+2,count+1);
    set(i+2,j+1,count+1);
    board[i][j] = 1;//sets (i,j) cell again(backtracking)
}
int main(){
//	freopen("input.txt","r",stdin);
    
	cin>>n;
    sum = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        	cin>>board[i][j];
        	if(board[i][j])
        		sum++; // sum stroes total number of valid cells on chessboard
        }
    }
	hi=0;
	set(0,0,0);
    cout<<sum-hi<<"\n";
    return 0;
}