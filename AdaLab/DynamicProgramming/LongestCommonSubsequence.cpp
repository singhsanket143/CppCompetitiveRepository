#include <bits/stdc++.h>
using namespace std;

void lcsprint( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   int index = L[m][n];
   char lcs[index+1];
   lcs[index] = ' '; 
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1];
          i--; j--; index--;     
      }
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

int lcsdp( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   int i, j; 
   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
   return L[m][n]; 
} 

int lcs( char *X, char *Y, int m, int n ) 
{ 
   if (m == 0 || n == 0) 
     return 0; 
   if (X[m-1] == Y[n-1]) 
     return 1 + lcs(X, Y, m-1, n-1); 
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 

int main(int argc, char const *argv[])
{
	char X[] = "AGGTAB"; 
  	char Y[] = "GXTXAYB"; 
  
  	int m = strlen(X); 
  	int n = strlen(Y); 
	printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
	printf("Length of LCS BY DP is %d\n", lcs( X, Y, m, n ) );
	lcsprint(X, Y, m, n);
	return 0;
}
