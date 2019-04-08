/*
By Sanket Singh
*/
#include <iostream>
using namespace std;
int dp[10][30];
int knapSackBtr(int* vals, int* wts, int wt, int si, int storage[][30], int n) {
		if (si == n || wt <= 0) {
			return 0; 
		}

		if (storage[wt][si] != 0) {
			return storage[wt][si];
		}

		int rv = 0;

		if (wts[si] <= wt) {
			int f1 = 0 + knapSackBtr(vals, wts, wt, si + 1, storage, n);
			int f2 = vals[si] + knapSackBtr(vals, wts, wt - wts[si], si + 1, storage, n);

			rv = max(f1, f2);
		} else {
			rv = knapSackBtr(vals, wts, wt, si + 1, storage, n);
		}

		storage[wt][si] = rv;
		return rv;
}

int knapSackbtr2(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
}

int main(int argc, char const *argv[])
{
	int vals[] = { 2, 4, 5, 10, 3 };
	int wts[] = { 10, 50, 80, 30, 100 };
	int wt = 30;
	
	cout<<knapSackBtr(vals, wts, wt, 0, dp, 5);
	return 0;
}
