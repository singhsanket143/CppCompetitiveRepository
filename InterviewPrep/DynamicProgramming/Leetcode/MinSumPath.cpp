#include<iostream>
 #include<vector>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input a 2D array
 // It should return the required output
 
 int maze(vector<vector<int>> &arr) {
     // Write your code here
     int n=arr.size();
        int m=arr[0].size();
        int **dp = new int*[n];
        for(int i=0;i<n;i++) {
            dp[i] = new int[m];
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j] = 0;
            }
        }
        
        
        dp[0][0] = arr[0][0];
        for(int i=1;i<n;i++) {
            dp[i][0] = arr[i][0] + dp[i-1][0];
        }
        for(int i=1;i<m;i++) {
            dp[0][i] = arr[0][i] + dp[0][i-1];
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+arr[i][j];
            }
        }

        return dp[n-1][m-1];
 }
 
 int main(int argc,char**argv){
 
     int r,c;
     cin>>r>>c;
     vector< vector<int> >A(r,vector<int>(c));
     for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
             cin>>A[i][j];
         }
     }   
     cout<<maze(A)<<endl;
         
     
 }