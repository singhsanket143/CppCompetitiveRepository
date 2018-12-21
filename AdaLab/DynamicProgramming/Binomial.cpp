/*
By Sanket Singh
*/
#include<iostream>
using namespace std; 
int binomialCoeff(int n, int k) 
{ 
    int C[n+1][k+1]; 
    int i, j; 
  
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 
int main() 
{ 
    int n = 5, k = 2; 
    cout<<binomialCoeff(n, k) ; 
    return 0; 
} 